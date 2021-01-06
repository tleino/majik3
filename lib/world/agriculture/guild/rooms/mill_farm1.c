#include "../path.h"
inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  //set_save_file("/home/madrid/agriculture/mill_farm1.o");
  add_exit("west",ROOM_PATH +"mill_farm6.c");
  add_exit("east", ROOM_PATH + "road9.c");
  add_exit("south", ROOM_PATH + "mill_farm2.c");
}
