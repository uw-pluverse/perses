



__thread struct
{
  int a;
  char b[32];
} thr;

int
main ()
{
  __builtin_strcpy (thr.b, "abcd");
  return 0;
}
