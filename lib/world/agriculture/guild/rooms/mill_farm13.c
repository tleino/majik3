#include "../path.h"

inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  add_exit("south", ROOM_PATH + "mill_farm14.c");
  add_exit("north", ROOM_PATH + "road7.c");
}
