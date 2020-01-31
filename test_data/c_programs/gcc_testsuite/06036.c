


extern void abort(void);
void foo(int *p)
{
  while (1)
   {
      *p = 1;
      *p = 0;
   }
}
void bar(int *p)
{
  *p = 1;
  *p = 0;
  abort ();
}
