void foo();
void bar();
void fold_if(int a, int b) {
  if (a && b)
    foo();
  else
    bar();
}
