/*
 * This is a web client to Majik 3 MUD.
 * (c) 2021, Tommi Leino.
 */

const wshost = "wss://majik3d-legacy.org:4003";

var lineno = 0;
var topelem = null;
var body;
var prompt;
var content;
var socket;
var focuseddiv = null;
var selecting = false;

function openws()
{
	socket = new WebSocket(wshost);

	addline("Trying " + wshost + "...");

	socket.onopen = function(e) {
		addline("Connected to " + wshost + ".");
		addline("");
		prompt.style.visibility = "visible";
		prompt.scrollIntoView();
	}

	socket.onmessage = function(e) {
		addline(e.data, "wsline");
	}

	socket.onclose = function(e) {
		prompt.style.visibility = "hidden";
		var r = confirm("Lost connection -- restart?");
		if (r == true) {
			addline("");
			addline("* * *");
			addline("");
			openws();
		} else {
			addline("", "restart");
		}
	}

	socket.onerror = function(error) {
		prompt.style.visibility = "hidden";
		console.log("WS error" + error);
		confirm("Connection error: " + error.message +
		    " -- try again?");
		if (r == true) {
			addline("");
			addline("* * *");
			addline("");
			openws();
		} else {
			addline("", "restart");
		}
	}
}

function addline(linetext, classname)
{
	var bounding = prompt.getBoundingClientRect();
	var visible;

	if (classname == "restart") {
		p = document.createElement("a");
		p.id = "restartbtn";
		p.href = "webclient.html";
		p.className = "wsline";
		p.textContent = ">> RESTART <<";
		content.insertBefore(p, prompt);
		return;
	}

	const colors = {
                 "^c0" : "c0",  "^c1" : "c1",
                 "^c6" : "c6",
                 "^cl" : "cl",  "^cr" : "cr",  "^cg" : "cg",
                 "^cy" : "cy",  "^cb" : "cb",  "^cp" : "cp",
                 "^cc" : "cc",  "^cw" : "cw",
                 "^cL" : "cll",  "^cR" : "crr",  "^cG" : "cgg",
                 "^cY" : "cyy",  "^cB" : "cbb",  "^cP" : "cpp",
                 "^cC" : "ccc",  "^cW" : "cww",
		 "^bb" : "bb"
	}

	p = document.createElement("div");

	if (linetext == "") {
		classname = "invis";
		linetext = "~";
	}
	p.className = classname;
	content.insertBefore(p, prompt);

	var begin = 0;
	var currentspan = document.createElement("span");
	var currentkey = "c0";
	p.appendChild(currentspan);

	if (classname == "userinput") {
		p.className = "wsline userinputdiv";
		if (focuseddiv != null)
			focuseddiv.firstChild.style.backgroundColor = "#555555";
		focuseddiv = null;
		currentspan.addEventListener("click", repcmd);
		currentspan.className = "userinput";
	}

	var i = 0;
	var stickycode = 0;
	var len = linetext.length;

	while (i < len) {
		var code, key, newspan, category;

		/*
		 * Parse ^H and do the thing that is needed: this is
		 * because Majik 3 MUD uses help pages that are generated
		 * using troff.
		 */
		if (linetext.charCodeAt(i) == 0x08) {
			var begin;
			var end;
			begin = linetext.substr(0, i);
			end = linetext.substr(i+1);
			linetext = begin + end;
			len = linetext.length;
			continue;
		}

		/*
		 * Parse Majik 3 MUD specific control codes.
		 */
		if (i < linetext.length - 2 &&
		    linetext[i] == '^' && (linetext[i+1] == 'c' ||
		    linetext[i+1] == 'b')) {
			category = linetext[i+1];
			code = linetext[i+2];
			key = "^" + category + code;

			if (category == 'c') {
				if (code == 1)
					stickycode = 1;
				else
					stickycode = 0;
			}

			currentspan.textContent =
			    linetext.substr(begin, i-begin);

			newspan = document.createElement("span");
			newspan.className = colors[key];
			if (stickycode == 1)
				newspan.className += " bold";

			/* Add after previous span node */
			currentspan.parentNode.insertBefore(newspan,
			    currentspan.nextSibling);

			currentspan = newspan;

			i += 3;
			begin = i;
		} else
			i++;
	}
	currentspan.textContent = linetext.substr(begin);

	if (
	    bounding.top >= 0 &&
	    bounding.left >= 0 &&
	    bounding.right <= window.innerWidth &&
	    bounding.bottom <= window.innerHeight)
		visible = 1;
	else
		visible = 0;

	lineno++;

	if (topelem == null)
		topelem = p;

	if (lineno > 200) {
		nextelem = topelem.nextSibling;
		topelem.remove();
		topelem = nextelem;
	}

	if (visible)
		prompt.scrollIntoView();
}

function repcmd(e)
{
	prompt.value = e.target.textContent;
	stealfocus();
}

function init()
{
	body = document.getElementById("body");
	content = document.getElementById("content");
	prompt = document.getElementById("prompt");

	openws();
}

/*
 * Fancy feature:
 *   Support UP and DOWN arrow keys, for scrolling to a next/previous
 *   user entered string.
 */
function arrowdown(e) {
	e = e || window.event;

	var fc;
	if (focuseddiv != null)
		fc = focuseddiv.firstChild;

	if (e.keyCode == 38) {
		var x = document.getElementsByClassName("userinputdiv");
		var i;
		if (x.length > 0 && focuseddiv == null) {
			focuseddiv = x[x.length-1];
			fc = focuseddiv.firstChild;
			fc.style.backgroundColor = "red";
		} else {
			for (i = 1; i < x.length; i++) {
				if (x[i] == focuseddiv) {
					fc.style.backgroundColor = "#555555";
					focuseddiv = x[i-1];
					focuseddiv.scrollIntoView();
					fc = focuseddiv.firstChild;
					fc.style.backgroundColor = "red";
					break;
				}
			}
		}
		e.preventDefault();
	} else if (e.keyCode == 40 && focuseddiv != null) {
		var x = document.getElementsByClassName("userinputdiv");
		var i;
		for (i = 0; i < x.length; i++) {
			if (x[i] == focuseddiv && i < x.length - 1) {
				fc.style.backgroundColor = "#555555";
				focuseddiv = x[i+1];
				focuseddiv.scrollIntoView();
				fc = focuseddiv.firstChild;
				fc.style.backgroundColor = "red";
				break;
			} else if (x[i] == focuseddiv) {
				fc.style.backgroundColor = "#555555";
				focuseddiv = null;
				stealfocus();
				break;
			}
		}
		e.preventDefault();
	} else if (e.keyCode == 40) {
		stealfocus();
		e.preventDefault();
	}
}

function enterclicked(e)
{
	e = e || window.event;
	if (e.keyCode == 38 || e.keyCode == 40) {
		e.preventDefault();
		return;
	}

	if (focuseddiv != null && e.keyCode == 13) {
		prompt.value += focuseddiv.firstChild.textContent;
		focuseddiv.firstChild.style.backgroundColor = "#555555";
		focuseddiv = null;
		stealfocus();
		return;
	}

	stealfocus();

	if (e.keyCode != 13 && e.which != 13)
		return;
		
	addline(prompt.value, "userinput");
	socket.send(prompt.value);

	prompt.value = "";
}

function stealfocus()
{
	if (window.getSelection && window.getSelection() != "")
		return;
	if (document.getSelection && document.getSelection() != "")
		return;

	if (focuseddiv != null)
		focuseddiv.firstChild.style.backgroundColor = "#555555";
	focuseddiv = null;
	prompt.scrollIntoView();
	prompt.focus();
}
