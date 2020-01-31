


extern void abort (void);

union tree_node;
typedef union tree_node *tree;
enum tree_code
{
  TREE_VEC = 20,
};
struct tree_common
{
  int code;
};
struct tree_type
{
  tree binfo;
};
union tree_node
{
  struct tree_common common;
  struct tree_type type;
};
void
record_component_aliases (type)
     tree type;
{
  const tree __z = type->type.binfo;
  if (type->type.binfo->common.code != TREE_VEC)
    abort ();

  if (__z->common.code != TREE_VEC)
    abort ();
}
