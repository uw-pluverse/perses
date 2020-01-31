




extern void abort (void);




int f1(int a, int b)
{
   return ((((a) > (b) ? (a) : (b))) < (b) ? (((a) > (b) ? (a) : (b))) : (b));
}

int f2(int a, int b)
{
   return ((((a) < (b) ? (a) : (b))) > (b) ? (((a) < (b) ? (a) : (b))) : (b));
}

int f3(int a, int b)
{
   return ((((b) > (a) ? (b) : (a))) < (b) ? (((b) > (a) ? (b) : (a))) : (b));
}

int f4(int a, int b)
{
   return ((((b) < (a) ? (b) : (a))) > (b) ? (((b) < (a) ? (b) : (a))) : (b));
}


int g1(int a, int b)
{
   return ((a) < (((a) > (b) ? (a) : (b))) ? (a) : (((a) > (b) ? (a) : (b))));
}

int g2(int a, int b)
{
   return ((a) > (((a) < (b) ? (a) : (b))) ? (a) : (((a) < (b) ? (a) : (b))));
}

int g3(int a, int b)
{
   return ((a) < (((b) > (a) ? (b) : (a))) ? (a) : (((b) > (a) ? (b) : (a))));
}

int g4(int a, int b)
{
   return ((a) > (((b) < (a) ? (b) : (a))) ? (a) : (((b) < (a) ? (b) : (a))));
}

int main(void)
{
  if (f1 (1, 2) != 2)
    abort ();

  if (f2 (1, 2) != 2)
    abort ();

  if (f3 (1, 2) != 2)
    abort ();

  if (f4 (1, 2) != 2)
    abort ();

  if (g1 (1, 2) != 1)
    abort ();

  if (g2 (1, 2) != 1)
    abort ();

  if (g3 (1, 2) != 1)
    abort ();

  if (g4 (1, 2) != 1)
    abort ();

  return 0;
}
