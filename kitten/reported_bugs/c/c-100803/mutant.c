int fieldlist;
int __GIMPLE foo() {
  if (bar(&fieldlist))
    goto bb1;
  else
    goto bb2;
bb1:
  a_1 = 10;
  return a_1;
bb2:
  return 1;
}
