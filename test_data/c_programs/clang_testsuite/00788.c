int bar();
int foo(int i) {
 int j = 0;
 if (i) {
  j = bar();
 }
 else
 {
  j = bar() + 2;
 }
 return j;
}
