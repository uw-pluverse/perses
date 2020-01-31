



int *a, *b, c;
void *jmpbuf[10];

void foo()
{
  int j;

 for (int i=0; i < 1000; ++i)
    {
      if (c == 6)
 __builtin_setjmp (jmpbuf);
      a[i] = b[i];
    }

 for (int i=0; i < 1000; ++i)
    {
      if (c==5)
 break;
    }

 for (int i=0; i < 1000; ++i)
    {
 for (j=0; j < 1000; ++j)
 a[i] = b[i];
    }
}
