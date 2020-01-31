enum demangle_component_type
{
 DEMANGLE_COMPONENT_TRINARY_ARG2,
};
struct demangle_component
{
  enum demangle_component_type type;
};
struct d_info
{
  int next_comp;
  int num_comps;
};
struct demangle_component * d_make_empty (struct d_info *di)
{
  if (di->next_comp >= di->num_comps) return ((void *)0);
  ++di->next_comp;
}
struct demangle_component *d_make_comp (
 struct d_info *di,
 enum demangle_component_type type,
 struct demangle_component *left)
{
  struct demangle_component *p;
  switch (type)
    {
    case DEMANGLE_COMPONENT_TRINARY_ARG2:
      if (left == ((void *)0)) return ((void *)0);
    }
  p = d_make_empty (di);
  p->type = type;
}
