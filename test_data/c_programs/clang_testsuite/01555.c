int stmtexpr_fn();
void stmtexprs(int i) {
  __builtin_assume( ({ 1; }) );
  __builtin_assume( ({ if (i) { (void)0; }; 42; }) );
  __builtin_assume( ({ if (i) ({ stmtexpr_fn(); }); 1; }) );
}
