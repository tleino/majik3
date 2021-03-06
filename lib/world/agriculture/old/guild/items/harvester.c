#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"harvester"}));
  set_short("a harvester of sorrow");
  set_long(wrap("Made of wood and stone, this contraption is very large. "
   + "The front end is a rotating cyclinder with blades on it. The cyclinder "
   + "is attached to two wheels via a leather belt, which cause it to rotate "
   + "as it is pushed. There are two handles at back end which provide good grip "
   + "while pushing the machine.\n"));

  set_material("wood");
  set_dimensions(50, 30, 70);
}
