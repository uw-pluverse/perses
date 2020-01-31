




char a[1*1024*1024*1024];
char b[1*1024*1024*1024];
char c[1*1024*1024*1024];

extern int bar();
int main()
{
  return bar() + c[225];
}
