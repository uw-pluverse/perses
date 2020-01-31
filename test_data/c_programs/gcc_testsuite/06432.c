



extern void bar(int *);

int foo (int *p)
{
    int i = *p;
    if (i != 1)
      bar(&i);
    *p = i;
}
