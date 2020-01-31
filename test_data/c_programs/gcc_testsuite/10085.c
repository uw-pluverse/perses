



extern void perhaps_free_something (void);

void f1 (int *p, int a, int b, int cond, int cond2)
{
  *p = a;
  if (cond)
    perhaps_free_something ();
  if (cond2)
    *p = b;
}

void f2 (int *p, int a, int b, int *cond, int *cond2)
{
  int i;
  *p = a;
  for (i = 0; cond[i]; i++)
    {
      if (cond2[i])
        *p = b;
      perhaps_free_something ();
    }
}
