


extern void abort (void);

union tree_node;
typedef union tree_node *tree;
extern const char tree_code_type[];

union tree_node
{
  int code;
  long pointer_alias_set;
};

long
get_alias_set (t)
     tree t;
{
  if (tree_code_type[t->code])
    abort ();
  if (t->pointer_alias_set)
    {
      tree __t = t;
      if (tree_code_type[__t->code])
 abort ();
    }
}
