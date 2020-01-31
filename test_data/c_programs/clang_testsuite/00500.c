extern int bar(char *A, int n);
int foo (int n) {
  if (n) {
    char A[100];
    return bar(A, 1);
  } else {
    char A[100];
    return bar(A, 2);
  }
}
void no_goto_bypass() {
  char x;
l1:
  bar(&x, 1);
  char y[5];
  bar(y, 5);
  goto l1;
}
void goto_bypass() {
  {
    char x;
  l1:
    bar(&x, 1);
  }
  goto l1;
}
void no_switch_bypass(int n) {
  switch (n) {
  case 1: {
    char x;
    bar(&x, 1);
    break;
  }
  case 2:
    n = n;
    char y[5];
    bar(y, 5);
    break;
  }
}
void switch_bypass(int n) {
  switch (n) {
  case 1:
    n = n;
    char x;
    bar(&x, 1);
    break;
  case 2:
    bar(&x, 1);
    break;
  }
}
void indirect_jump(int n) {
  char x;
  void *T[] = {&&L};
  goto *T[n];
L:
  bar(&x, 1);
}
extern void foo2(int p);
int jump_backward_over_declaration(int a) {
  int *p = 0;
label1:
  if (p) {
    foo2(*p);
    return 0;
  }
  int i = 999;
  if (a != 2) {
    p = &i;
    goto label1;
  }
  return -1;
}
