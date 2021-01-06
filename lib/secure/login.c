/*
 * LOGIN OBJECT
 *
 */

/* function prototypes */

void logon();
void do_timeout();
void get_name (string);
void ask_name ();
void ask_pass ();
void get_pass (string);
void newuser ();

int test_user (string);

/* global variables */

int tries;
string password, name = "null";
string login_term = "unknown";
int login_rows = 24;
int login_columns = 80;
int login_real_term = 0;

void terminal_type (string term)
{
  write_file ("/log/telnet", "login: terminal_type received: "+term+"\n");
  login_term = term;

  if (login_term[0..1] == "vt")
    login_real_term = 1;
  else if (login_term[0..4] == "linux" ||
           login_term[0..3] == "ansi")
    login_real_term = 2;
}

void window_size (mixed jotai1, mixed jotai2)
{
  write_file ("/log/telnet", "login: window_size: "+sprintf("%O, %O\n",
    jotai1, jotai2));

  login_columns = jotai1;
  login_rows = jotai2;
}

void
logon ()
{
  call_out ("do_timeout", 300);
  efun::write ("\033[H\033[J" + read_file("/data/config/welcome") + "\n");

  ask_name();
}

void
ask_name ()
{
  efun::write ("What is your character's name? ");
  input_to ("get_name", 0);
}

void
ask_pass ()
{
  efun::write ("Password: ");
  input_to ("get_pass", 1);
}

void
do_timeout ()
{
  efun::write ("\nSorry. Timeout limit reached.\n\n");
  destruct (THOB);
}

int
test_user (string str)
{
  if (file_size ("/data/player/" + str[0..0] + "/" + str + ".o") > 0)
    return 1;
  else
    return 0;
}

void
get_name (string str)
{
  str = lower_case (str);

  if (str == "new")
    {
      efun::write (read_file("/data/config/newuser"));
      newuser();
      return;
    }
  else if (!test_user (str))
    {
      efun::write ("No character with that name exists.\n");
      efun::write ("To create new character please login as 'new'.\n\n");
      tries++;
    }
  else
    {
      name = str;
      ask_pass ();
      return;
    }

  if (tries > 2)
    {
      efun::write ("Too many login failures.\n\n");
      destruct (THOB);
    }

  ask_name ();
}

void
get_pass (string str)
{
  object o;

  if (restore_object ("/data/player/" + name[0..0] + "/" + name))
    {
      if (!password || password == "")
        {
          efun::write ("\nYou have no password.\n\n");
        }
      else if (crypt (str, password) != password)
        {
          efun::write ("\nLogin incorrect.\n\n");
          ask_name();
          return;
        }
    }
  else
    {
      efun::write ("\nError: Couldn't restore the object!\n\n");
      ask_name();
      return;
    }

  if (name)
    {
      o = find_player (name);

      if (o)
        {
          o->save_me();
          efun::write ("\nRecovering character...\n\n");

            if (interactive (o))
              {
                if (ENV(o))
                  act (o, "$n twiches briefly.");

                destruct (o);

                o = new ("/secure/player");
                o->setup (name);
              }

          o->reconnect ();
          efun::exec (o, THOB);
          destruct (THOB);
        }
      else
        {
          o = new ("/secure/player");
          o->setup (name);
          efun::exec (o, THOB);
          destruct (THOB);
        }
    }
}

void
newuser ()
{
  object o;

  o = new ("/secure/newuser");
  efun::exec(o, THOB);
  o->do_newuser ();
  destruct (THOB);
}

int
clean_up ()
{
  destruct (THOB);
  return 1;
}

string
query_name ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_cap_name ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_true_name ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_short ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
short ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}
