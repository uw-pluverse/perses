








extern



void abort (void);

int last;

void
bar (unsigned char *a, int i, int safelen)
{
  int j, k;
  if (i != last++)
    abort ();
  for (j = i - safelen - 32; j < i; j++)
    if (j >= 0 && a[j] != 2)
      break;
  if (j <= i - safelen || a[j] != 1)
    abort ();
  for (k = j; k < i + safelen + 32; k++)
    if (k >= 1024 || a[k] != 1)
      break;
  if (k <= i || k > j + safelen)
    abort ();
  if (k < 1024 && a[k] != 0)
    abort ();
  for (; k < i + safelen + 32; k++)
    if (k < 1024 && a[k] != 0)
      abort ();
}

static inline void
foo (unsigned char *a, int i)
{
 bar (a, i, 64);
}

int
main ()
{
  unsigned char a[1024], b[1024];
  int i;
 for (i = 0; i < 1024; i++)
    a[i] = 0;
 for (i = 0; i < 1024; i++)
    {
      a[i]++;
      foo (a, i);
      a[i]++;
    }
 for (i = 0; i < 1024; i++)
    {
      a[i] = 0;
      b[i] = 0;
    }
  last = 0;
 for (i = 0; i < 1024; i++)
    {
      a[i]++;
 bar (a, i, 32);
      a[i]++;
    }
  for (i = 0; i < 1024; i++)
    if (a[i] != 2)
      abort ();
 for (i = 1; i < 1024; i++)
    {
 b[i] = b[i - 1] + 1;
      a[i]++;
 a[i] += a[i - 1];
    }
  for (i = 0; i < 1024; i++)
    if (a[i] != (unsigned char) (2 + 3 * i) || b[i] != (unsigned char) i)
      abort ();
  return 0;
}

