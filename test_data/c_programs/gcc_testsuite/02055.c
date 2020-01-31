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
  int len;
  char *p;


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf, '\0', len);
      if (p != u.buf) abort ();
      check (0, len, '\0');

      p = memset (u.buf, A, len);
      if (p != u.buf) abort ();
      check (0, len, 'A');

      p = memset (u.buf, 'B', len);
      if (p != u.buf) abort ();
      check (0, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+1, '\0', len);
      if (p != u.buf+1) abort ();
      check (1, len, '\0');

      p = memset (u.buf+1, A, len);
      if (p != u.buf+1) abort ();
      check (1, len, 'A');

      p = memset (u.buf+1, 'B', len);
      if (p != u.buf+1) abort ();
      check (1, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+2, '\0', len);
      if (p != u.buf+2) abort ();
      check (2, len, '\0');

      p = memset (u.buf+2, A, len);
      if (p != u.buf+2) abort ();
      check (2, len, 'A');

      p = memset (u.buf+2, 'B', len);
      if (p != u.buf+2) abort ();
      check (2, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+3, '\0', len);
      if (p != u.buf+3) abort ();
      check (3, len, '\0');

      p = memset (u.buf+3, A, len);
      if (p != u.buf+3) abort ();
      check (3, len, 'A');

      p = memset (u.buf+3, 'B', len);
      if (p != u.buf+3) abort ();
      check (3, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+4, '\0', len);
      if (p != u.buf+4) abort ();
      check (4, len, '\0');

      p = memset (u.buf+4, A, len);
      if (p != u.buf+4) abort ();
      check (4, len, 'A');

      p = memset (u.buf+4, 'B', len);
      if (p != u.buf+4) abort ();
      check (4, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+5, '\0', len);
      if (p != u.buf+5) abort ();
      check (5, len, '\0');

      p = memset (u.buf+5, A, len);
      if (p != u.buf+5) abort ();
      check (5, len, 'A');

      p = memset (u.buf+5, 'B', len);
      if (p != u.buf+5) abort ();
      check (5, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+6, '\0', len);
      if (p != u.buf+6) abort ();
      check (6, len, '\0');

      p = memset (u.buf+6, A, len);
      if (p != u.buf+6) abort ();
      check (6, len, 'A');

      p = memset (u.buf+6, 'B', len);
      if (p != u.buf+6) abort ();
      check (6, len, 'B');
    }


  for (len = 0; len < 15; len++)
    {
      reset ();

      p = memset (u.buf+7, '\0', len);
      if (p != u.buf+7) abort ();
      check (7, len, '\0');

      p = memset (u.buf+7, A, len);
      if (p != u.buf+7) abort ();
      check (7, len, 'A');

      p = memset (u.buf+7, 'B', len);
      if (p != u.buf+7) abort ();
      check (7, len, 'B');
    }

  exit (0);
}
