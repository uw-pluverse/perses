




enum test_type
{
  TYPE0,
  TYPE1
};

struct type_node
{
  enum test_type type;
};

struct test_ref
{
  struct type_node *referring;
};

struct test_node
{
  struct test_node *next;
};

int iterate (struct test_node *, unsigned, struct test_ref **);

int
loop_invar (struct test_node *node)
{
  struct test_ref *ref;

  for (unsigned i = 0; iterate (node, i, &ref); i++)
    if (loop_invar ((ref->referring && ref->referring->type == TYPE0)
                    ? ((struct test_node *) (ref->referring)) : 0))
      return 1;

  return 0;
}
