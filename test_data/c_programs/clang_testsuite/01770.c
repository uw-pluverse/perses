int a();
int b();
int c();
void testRemoveDeadBindings() {
  int i = a();
  if ((i))
    a();
  else
    b();
  c();
}
