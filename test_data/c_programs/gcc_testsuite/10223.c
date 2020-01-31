





struct tree
{
    struct tree *car, *cdr, *wfl;
    int code;
    struct { unsigned int renp:1;
      unsigned int rtnp:1;
      unsigned int rpnp:1; } flags;
};
typedef struct tree *tree;



enum
{
    CALL_EXPR, NEW_ARRAY_EXPR, NEW_CLASS_EXPR, CONVERT_EXPR,
    ARRAY_REF, CONDITIONAL_EXPR, STRING_CST, EXPR_WITH_FILE_LOCATION
};
extern tree current_class, this_identifier_node;
extern tree super_identifier_node, length_identifier_node;

tree resolve_and_layout (tree, tree);
tree lookup_field_wrapper (tree, tree);

void
qualify_ambiguous_name (id)
     tree id;
{
  tree qual, qual_wfl, decl;
  tree name;
  tree ptr_type;
  int again, new_array_found = 0;
  int super_found = 0, this_found = 0;

  qual = ((id)->wfl);
  do {
    qual_wfl = ((qual)->wfl);
    switch (((qual_wfl)->code))
      {
      case CALL_EXPR:
 qual_wfl = ((qual_wfl)->car);
 if (((qual_wfl)->code) != EXPR_WITH_FILE_LOCATION)
   {
     qual = ((qual_wfl)->wfl);
     qual_wfl = ((qual)->wfl);
   }
 break;
      case NEW_ARRAY_EXPR:
 qual = ((qual)->cdr);
 new_array_found = again = 1;
 continue;
      case NEW_CLASS_EXPR:
      case CONVERT_EXPR:
 qual_wfl = ((qual_wfl)->car);
 break;
      case ARRAY_REF:
 while (((qual_wfl)->code) == ARRAY_REF)
   qual_wfl = ((qual_wfl)->car);
 break;
      default:
 break;
      }

    name = ((qual_wfl)->wfl);
    ptr_type = current_class;
    again = 0;

  } while (again);





  if (!this_found && !super_found && (decl = ((name)->car)))
    {
      ((qual_wfl)->flags.renp) = 1;
      ((qual)->cdr) = decl;
    }
  else if ((decl = lookup_field_wrapper (ptr_type, name))
    || (new_array_found && name == length_identifier_node))
    {
      ((qual_wfl)->flags.renp) = 1;
      ((qual)->cdr) = (new_array_found ? ((tree)0) : decl);
    }
  else if ((decl = resolve_and_layout (name, ((tree)0))))
    {
      ((qual_wfl)->flags.rtnp) = 1;
      ((qual)->cdr) = decl;
    }
  else if (((((qual)->wfl))->code) == CALL_EXPR
    || ((((qual)->wfl))->code) == ARRAY_REF)
    ((qual_wfl)->flags.renp) = 1;
  else
    ((qual_wfl)->flags.rpnp) = 1;
}
