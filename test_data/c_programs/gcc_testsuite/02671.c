static union {
  char buf[((sizeof (long long)) + 15 + (sizeof (long long)))];
  long long align_int;
  long double align_fp;
} u;

char A = 'A';

void reset ()
{
  int i;

  for (i = 0; i < ((sizeof (long long)) + 15 + (sizeof (long long))); i++)
    u.buf[i] = 'a';
}

void check (int off, int len, int ch)
{
  char *q;
  int i;

  q = u.buf;
  for (i = 0; i < off; i++, q++)
    if (*q != 'a')
      abort ();

  for (i = 0; i < len; i++, q++)
    if (*q != ch)
      abort ();

  for (i = 0; i < (sizeof (long long)); i++, q++)
    if (*q != 'a')
      abort ();
}

int main ()
{
  int off;
  char *p;


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 1);
      if (p != u.buf + off) abort ();
      check (off, 1, '\0');

      p = memset (u.buf + off, A, 1);
      if (p != u.buf + off) abort ();
      check (off, 1, 'A');

      p = memset (u.buf + off, 'B', 1);
      if (p != u.buf + off) abort ();
      check (off, 1, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 2);
      if (p != u.buf + off) abort ();
      check (off, 2, '\0');

      p = memset (u.buf + off, A, 2);
      if (p != u.buf + off) abort ();
      check (off, 2, 'A');

      p = memset (u.buf + off, 'B', 2);
      if (p != u.buf + off) abort ();
      check (off, 2, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 3);
      if (p != u.buf + off) abort ();
      check (off, 3, '\0');

      p = memset (u.buf + off, A, 3);
      if (p != u.buf + off) abort ();
      check (off, 3, 'A');

      p = memset (u.buf + off, 'B', 3);
      if (p != u.buf + off) abort ();
      check (off, 3, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 4);
      if (p != u.buf + off) abort ();
      check (off, 4, '\0');

      p = memset (u.buf + off, A, 4);
      if (p != u.buf + off) abort ();
      check (off, 4, 'A');

      p = memset (u.buf + off, 'B', 4);
      if (p != u.buf + off) abort ();
      check (off, 4, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 5);
      if (p != u.buf + off) abort ();
      check (off, 5, '\0');

      p = memset (u.buf + off, A, 5);
      if (p != u.buf + off) abort ();
      check (off, 5, 'A');

      p = memset (u.buf + off, 'B', 5);
      if (p != u.buf + off) abort ();
      check (off, 5, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 6);
      if (p != u.buf + off) abort ();
      check (off, 6, '\0');

      p = memset (u.buf + off, A, 6);
      if (p != u.buf + off) abort ();
      check (off, 6, 'A');

      p = memset (u.buf + off, 'B', 6);
      if (p != u.buf + off) abort ();
      check (off, 6, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 7);
      if (p != u.buf + off) abort ();
      check (off, 7, '\0');

      p = memset (u.buf + off, A, 7);
      if (p != u.buf + off) abort ();
      check (off, 7, 'A');

      p = memset (u.buf + off, 'B', 7);
      if (p != u.buf + off) abort ();
      check (off, 7, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 8);
      if (p != u.buf + off) abort ();
      check (off, 8, '\0');

      p = memset (u.buf + off, A, 8);
      if (p != u.buf + off) abort ();
      check (off, 8, 'A');

      p = memset (u.buf + off, 'B', 8);
      if (p != u.buf + off) abort ();
      check (off, 8, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 9);
      if (p != u.buf + off) abort ();
      check (off, 9, '\0');

      p = memset (u.buf + off, A, 9);
      if (p != u.buf + off) abort ();
      check (off, 9, 'A');

      p = memset (u.buf + off, 'B', 9);
      if (p != u.buf + off) abort ();
      check (off, 9, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 10);
      if (p != u.buf + off) abort ();
      check (off, 10, '\0');

      p = memset (u.buf + off, A, 10);
      if (p != u.buf + off) abort ();
      check (off, 10, 'A');

      p = memset (u.buf + off, 'B', 10);
      if (p != u.buf + off) abort ();
      check (off, 10, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 11);
      if (p != u.buf + off) abort ();
      check (off, 11, '\0');

      p = memset (u.buf + off, A, 11);
      if (p != u.buf + off) abort ();
      check (off, 11, 'A');

      p = memset (u.buf + off, 'B', 11);
      if (p != u.buf + off) abort ();
      check (off, 11, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 12);
      if (p != u.buf + off) abort ();
      check (off, 12, '\0');

      p = memset (u.buf + off, A, 12);
      if (p != u.buf + off) abort ();
      check (off, 12, 'A');

      p = memset (u.buf + off, 'B', 12);
      if (p != u.buf + off) abort ();
      check (off, 12, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 13);
      if (p != u.buf + off) abort ();
      check (off, 13, '\0');

      p = memset (u.buf + off, A, 13);
      if (p != u.buf + off) abort ();
      check (off, 13, 'A');

      p = memset (u.buf + off, 'B', 13);
      if (p != u.buf + off) abort ();
      check (off, 13, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 14);
      if (p != u.buf + off) abort ();
      check (off, 14, '\0');

      p = memset (u.buf + off, A, 14);
      if (p != u.buf + off) abort ();
      check (off, 14, 'A');

      p = memset (u.buf + off, 'B', 14);
      if (p != u.buf + off) abort ();
      check (off, 14, 'B');
    }


  for (off = 0; off < (sizeof (long long)); off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 15);
      if (p != u.buf + off) abort ();
      check (off, 15, '\0');

      p = memset (u.buf + off, A, 15);
      if (p != u.buf + off) abort ();
      check (off, 15, 'A');

      p = memset (u.buf + off, 'B', 15);
      if (p != u.buf + off) abort ();
      check (off, 15, 'B');
    }

  exit (0);
}
