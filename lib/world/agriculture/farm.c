inherit "/world/agriculture/farm_room.c";

clean_up ()
{
  return 0;
}

config(object vmap)
{
  vmap->set_no_clean_up(1);
}
