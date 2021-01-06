#include "../path.h"

inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  add_exit("west", ROOM_PATH + "mill_farm9.c");
  add_exit("south", ROOM_PATH + "mill_farm12.c");
}
