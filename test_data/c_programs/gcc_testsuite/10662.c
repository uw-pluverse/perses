


void
expand_stmt_with_iterators_1 (void)
{
  extern void expand_expr_stmt (void);
  expand_expr_stmt ();
}
void
iterator_expand (void)
{
  expand_stmt_with_iterators_1 ();
}
