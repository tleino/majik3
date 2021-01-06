// DATE        : Sat Nov  1 21:10:08 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Inside the Sunflower Tavern");
  set_long (
    "The main room of the tavern is huge. Tables and benches are pl"
  + "aced neatly around the central pillar, the huge oak trunk. A "
  + "couple of the oaks lower limbs are growing inside the tavern "
  + "room, but they are used to hang lamps and lanterns. Everythin"
  + "g here is painted green and brown and decorated with silvery "
  + "leaves and golden flowers. The round windows near the ceiling"
  + " line let fresh air inside and the pipeweed smoke can escape "
  + "out through them. There's a long desk for ordering drinks and"
  + " food further east from here. Doorways lead to north and sout"
  + "h and stairs climb steeply up to the next floor.");

  add_exit ("up", ROOM_PATH + "reception.c");
  add_exit ("south", ROOM_PATH + "sideroom.c");
  add_exit ("north", ROOM_PATH + "gamblers.c");
  add_exit ("east", ROOM_PATH + "bar.c");
  add_exit ("west", ROOM_PATH + "innyard.c");
  add_door ("west", ROOM_PATH + "innyard.c","door", "wooden", 0, 0, 0);

  add_object ( MONSTER_PATH + "rumblebum.c");
  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
