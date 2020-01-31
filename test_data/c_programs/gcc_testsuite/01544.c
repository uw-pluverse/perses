


struct trailing
{
  unsigned m;
  short ary[];
} trailing =
  {.ary = {1}};

struct packed
{
  unsigned m;
  short ary[];
} __attribute__ ((packed)) packed =
  {.ary = {2}};
