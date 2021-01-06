// DATE        : Fri Jan 16 21:11:15 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Lovely fountain square");
  set_long (
    "A fountain made of some smooth grey stone gurgles happily at t"
  + "he center of the square and spouts water to the air. Trees ar"
  + "ch gently over the fountain square casting sheltering shadows"
  + " over the area. Cobblestoned streets lead to all four directi"
  + "ons.");

  add_exit ("west", ROOM_PATH + "spass2.c");
  add_exit ("south", ROOM_PATH + "mlane1.c");
  add_exit ("north", ROOM_PATH + "falan1.c");
  add_exit ("east", ROOM_PATH + "walk1.c");
  add_object ( ITEM_PATH + "fountain.c");
  add_object ( MONSTER_PATH + "belethan.c");

  set_outdoors (4);
  set_no_clean_up(1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
