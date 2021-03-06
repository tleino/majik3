// DATE        : Sun Dec 28 02:04:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dusky stairwell");
  set_long (
    "You're in a dimly lit stairwell. Steep narrow stairs lead down"
  + " from here. A candleholder is attached to the west wall and a"
  + " single red candle in it provides little light to the room. A"
  + " door opening leads north from here.");

  add_exit ("down", ROOM_PATH + "questa8.c");
  add_exit ("north", ROOM_PATH + "quelib.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
