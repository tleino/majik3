inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("martial arts parry");
    set_train_difficulty(20);
    set_base_percent(15);
    add_base_stat("str",40);  // Total of Base Stats is 100
    add_base_stat("dex",10);
    add_base_stat("siz",10);
    add_base_stat("agi",40);
    set_parent_skill("martial_arts");
}

