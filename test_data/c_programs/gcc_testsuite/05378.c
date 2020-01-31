


int w;
int bar (void) __attribute__ ((weak));
int bar (){
  w++;
}
void foo()
{
  bar();
}
