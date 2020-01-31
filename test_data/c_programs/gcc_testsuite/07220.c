






extern void *chk_fail_buf[];
extern volatile int chk_fail_allowed, chk_calls;
extern volatile int memcpy_disallowed, mempcpy_disallowed, memmove_disallowed;
extern volatile int memset_disallowed, strcpy_disallowed, stpcpy_disallowed;
extern volatile int strncpy_disallowed, stpncpy_disallowed, strcat_disallowed;
extern volatile int strncat_disallowed, sprintf_disallowed, vsprintf_disallowed;
extern volatile int snprintf_disallowed, vsnprintf_disallowed;

void *bar (int);
extern void *malloc (long unsigned int);

struct A
{
  int i, j, k;
};




void
foo (const struct A *x, int y, const unsigned char *z)
{
  unsigned int b;
  unsigned char *c = 0;

  b = (x->i & 0xff) == 1 ? 3 : 4;
  if (y)
    c = bar (x->j * x->k);

  const unsigned char *d = z;
  unsigned char *e = c;
  unsigned char *f = c + x->j * x->k;
  int g = 0;

  while (e < f)
    {
      unsigned int h = *d++;

      if (h & 128)
 {
   h = h - 128;
   g = e + h * b > f;
   if (g)
     h = (f - e) / b;
   if (b < 4)
     do
       {
  __builtin___memcpy_chk (e, d, 3, __builtin_object_size (e, 0));
  e += 3;
       }
     while (--h);
   else
     do
       {
  __builtin___memcpy_chk (e, d, 4, __builtin_object_size (e, 0));
  e += 4;
       }
     while (--h);
   d += b;
 }
      else
 {
   h *= b;
   g = e + h > f;
   if (g)
     h = f - e;
   __builtin___memcpy_chk (e, d, h, __builtin_object_size (e, 0));
   e += h;
   d += h;
 }
    }
}
unsigned char *
baz (const struct A *x, const unsigned char *z)
{
  unsigned int b;
  unsigned char *c = 0;

  b = (x->i & 0xff) == 1 ? 3 : 4;
  c = malloc (512);

  const unsigned char *d = z;
  unsigned char *e = c;
  unsigned char *f = c + x->j * x->k;
  int g = 0;

  while (e < f)
    {
      unsigned int h = *d++;

      if (h & 128)
 {
   h = h - 128;
   g = e + h * b > f;
   if (g)
     h = (f - e) / b;
   if (b < 4)
     do
       {
  __builtin___memcpy_chk (e, d, 3, __builtin_object_size (e, 0));
  e += 3;
       }
     while (--h);
   else
     do
       {
  __builtin___memcpy_chk (e, d, 513, __builtin_object_size (e, 0));
  e += 4;
       }
     while (--h);
   d += b;
 }
      else
 {
   h *= b;
   g = e + h > f;
   if (g)
     h = f - e;
   __builtin___memcpy_chk (e, d, h, __builtin_object_size (e, 0));

   e += 16;
   d += h;
 }
    }
  return c;
}
