#include "../path.h"

inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  //set_save_file("/home/madrid/agriculture/mill_farm7.o");
  add_exit("east", ROOM_PATH + "mill_farm9.c");
  add_exit("west", ROOM_PATH + "road10.c");
  add_exit("south", ROOM_PATH + "mill_farm8.c");
}
