inherit "obj/skill/obj/skill";
// Coder: Aluna

create_skill()
{
	set_skill_type("node");
	set_skill_name("names_of_form");
	set_train_difficulty(6);
	set_base_percent(5);
	add_base_stat("pow",30);  // Total of Base Stats is 100
	add_base_stat("int",30);
	add_base_stat("wis",40);
	set_parent_skill("true_names");
}


