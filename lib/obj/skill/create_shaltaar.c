inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_shaltaar");
  set_train_difficulty(2);
  set_base_percent(1);
  add_base_stat("wis",10);
  add_base_stat("pow",10);
  add_base_stat("int",50);
  add_base_stat("dex",30);
  set_parent_skill("upkeep");
  set_ep_cost(15);
  set_sp_cost(0);
  set_hp_cost(0);
  set_duration(3);
}
do_success(me,target,result)
 {
   object potion;
   if(present("orc dung",THIS) && present("bluish siren",THIS) && present("dragonroot",THIS))
   {
    write("You drop the bluish siren and dragonroot into the bag of orc dung and "
     + "watch is combine into some hardened substance.\n");
    message("standard",THIS->query_cap_name()+" drops a plant and a root into a "+
    "bag.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/bag_shaltaar.c");
    potion->move(THIS);
    destruct(present("orc dung",THIS));
    destruct(present("bluish siren",THIS));
    destruct(present("dragonroot",THIS));
    return 1;
  }
  else
  {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
  }

}
do_failure(me,target,result)
{
 object potion;
   if(present("orc dung",THIS) && present("bluish siren",THIS) && present("dragonroot",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/sack_shit.c");
    potion->move(THIS);
    destruct(present("orc dung",THIS));
    destruct(present("bluish siren",THIS));
    destruct(present("dragonroot",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}
