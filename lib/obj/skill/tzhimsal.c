inherit "obj/skill/obj/skill";
create_skill()
{
    set_skill_name("tzhimsal");
    set_train_difficulty(7);
    set_base_percent(25);
    add_base_stat("cha",10);  // Total of Base Stats is 100
    add_base_stat("int",40);
    add_base_stat("wis",50);
    set_parent_skill("language");
}

