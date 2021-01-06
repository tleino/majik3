#include "../path.h"
inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  //set_save_file("/home/madrid/agriculture/mill_farm4.o");
  add_exit("north", ROOM_PATH + "mill_farm5.c");
  add_exit("east", ROOM_PATH + "mill_farm3.c");
}
