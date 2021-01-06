// DATE        : Sun Feb 22 16:13:55 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of an elven treemansion");
  set_long (
    "You're standing before the frontdoor on an elven treemansion, "
  + "one of the homes of the nobility in Sol'daran. This manor see"
  + "ms to be larger than the others being tens of feet in height "
  + "and diameter. It truly is a magnificent sight. A silver bell "
  + "has been hung beside the door. Dainty stairs spiral down arou"
  + "nd the tree behind you.");

  add_exit ("down", ROOM_PATH + "mansground.c");
  add_exit ("west", ROOM_PATH + "mansent.c");

  add_item ("bell",
    "A silver bell has been hunged beside the door, apparently for "
  + "calling someone to open the door. A golden tree has been pict"
  + "ured on the bell's side. You can 'ring bell' to call someone "
  + "inside.\n");

  add_sound ("The wind blows softly up here.");
  add_sound ("You can see people hurrying down on the streets.");

  set_outdoors (4);

}

init_room()
{
  add_action ("do_ring", "ring");
}

do_ring(str)
{

 if (!str || str != "bell")
 { notify_fail ("ring what?");
   return 0;
 }

write ("You ring the bell couple of times.\n");
      message ("3", THIS->query_cap_name() +
      " rings the bell a couple of times.\n",
      ENV(THIS), THIS);
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansbed.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansbed2.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansent.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansden.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "manskit.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "manslib.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansliv.c");
      message ("3", "*Gong* Someone rings the doorbell.\n",
      ROOM_PATH + "mansmain.c");
      return 1;
}
