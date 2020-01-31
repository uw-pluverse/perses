

static int a1 (void)
{
    return 10;
}

static int a2 (void)
{
    return 0;
}

typedef int (*tp) (void);

static tp aa [] = {a2, a1, a1, a1, a1};

void setp (int (**pp) (void), int i)
{
  if (!i)
    *pp = aa [i];
  else
    *pp = aa [(i & 2) + 1];
}

int
main (void)
{
  int (*p) (void);
  int i;

  for (i = 0; i < 10; i ++)
    {
 setp (&p, i);
 p ();
    }

  return 0;
}
