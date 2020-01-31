






struct s
{
  int a;
};

extern int fn (int);
extern int fnb (int, int);
extern int fnc (int *);
extern int sprintf (char *, const char *, ...);

typedef long unsigned int uintptr_t;

void
foo (int a, int b, int n, int p, int *ptr, struct s *sptr,
     int *ap, int *bp, int **cp, char *ans, int (*fnp[8])(int))
{
  int len;

  a = a++;
  a = --a;
  a = ++a + b;
  a = a-- + b;
  ap[n] = bp[n++];
  ap[--n] = bp[n];
  ap[++n] = bp[--n];
  cp[n][n] = cp[n][n]++;
  cp[n][p] = cp[n][n++];
  *ptr++ = (uintptr_t)ptr++;
  sptr->a = sptr->a++;
  sptr->a = (uintptr_t)(sptr++);
  *ptr++ = fn (*ptr);
  a = b = a++;
  b = a = --b;
  a = 1 + (a = 1);
  a = (a = b);
  a = (a = b) + 1;
  a = (bp[a++] = b) + 1;
  a = b++ * b++;
  a = fnb (b++, b++);
  a = (*fnp[b++]) (b++);
  a = (*fnp[b]) (b++);
  a = (*fnp[b++]) (b);
  *ap = fnc (ap++);
  (a += b) + (a += n);
  a = (b, b++) + (b++, b);
  ap[a++] += a;
  ap[a+=1] += a;
  ap[a++] += a++;
  ap[a+=1] += a++;
  a = a++, b = a;
  b = a, a = a++;
  a = (b++ ? n : a) + b;
  b ? a = a++ : a;
  b && (a = a++);
  (a = a++) && b;
  b, (a = a++);
  (a = a++), b;
  a ^= b ^= a ^= b;

  a = a;
  a = (a++ && 4);
  a = ! (a++ && 4);
  a = - (a++ && 4);
  a = (double) (a++ && 4);
  len = sprintf (ans, "%d", len++);
  a = fn (a++);
  b++, (b + b);
  (a = b++), (a = b++);
  a = (b++, b++);
  a = b++ && b++;
  a = b++ || b++;
  a = (b++ ? b++ : a);
  a = (b++ ? a : b++);
  ap[a++] += bp[b];
  ap[a += 1] += 1;
  *ptr < 128 ? *ptr++ : *(ptr += 2);




  a = ((b & 1 ? 21 : 0)
       | (b & 2 ? 22 : 0)
       | (b & 3 ? 23 : 0)
       | (b & 4 ? 24 : 0)
       | (b & 5 ? 25 : 0)
       | (b & 6 ? 26 : 0)
       | (b & 7 ? 27 : 0)
       | (b & 8 ? 28 : 0)
       | (b & 9 ? 29 : 0)
       | (b & 10 ? 30 : 0)
       | (b & 11 ? 31 : 0)
       | (b & 12 ? 32 : 0)
       | (b & 13 ? 1 : 0)
       | (b & 14 ? 2 : 0)
       | (b & 15 ? 3 : 0)
       | (b & 16 ? 4 : 0)
       | (b & 17 ? 5 : 0)
       | (b & 18 ? 6 : 0)
       | (b & 19 ? 7 : 0)
       | (b & 20 ? 8 : 0)
       | (b & 21 ? 9 : 0));
}
