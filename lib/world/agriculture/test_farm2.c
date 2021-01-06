inherit "/home/madrid/agriculture/farm_room.c";
create_farm()
{
  set_short("Another farming plot");
  set_crop_type("corn");
  add_exit("west","/home/madrid/agriculture/test_farm1.c");
  add_exit("northwest","/home/madrid/agriculture/room.c");
}

