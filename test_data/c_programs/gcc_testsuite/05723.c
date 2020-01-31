


struct S
{
  int i;
  int j;
  char c[32];
};

extern struct S bar(void);

int foo1 (int b)
{
   struct S s1;

   s1 = bar ();
   return s1.i;
}

extern struct S *g;

int foo2 (void)
{
   struct S s2;

   s2 = *g;
   return s2.i;
}
