






extern void abort (void);


extern void *chk_fail_buf[];
extern volatile int chk_fail_allowed, chk_calls;
extern volatile int memcpy_disallowed, mempcpy_disallowed, memmove_disallowed;
extern volatile int memset_disallowed, strcpy_disallowed, stpcpy_disallowed;
extern volatile int strncpy_disallowed, stpncpy_disallowed, strcat_disallowed;
extern volatile int strncat_disallowed, sprintf_disallowed, vsprintf_disallowed;
extern volatile int snprintf_disallowed, vsnprintf_disallowed;
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

volatile void *vx;
char buf1[20];
int x;

void
test (int arg, ...)
{
  char buf2[20];
  va_list ap;
  char *p = &buf1[10], *q;

  __builtin___memcpy_chk (&buf2[19], "ab", 1, __builtin_object_size (&buf2[19], 0));
  __builtin___memcpy_chk (&buf2[19], "ab", 2, __builtin_object_size (&buf2[19], 0));
  vx = __builtin___mempcpy_chk (&buf2[19], "ab", 1, __builtin_object_size (&buf2[19], 0));
  vx = __builtin___mempcpy_chk (&buf2[19], "ab", 2, __builtin_object_size (&buf2[19], 0));
  __builtin___memmove_chk (&buf2[18], &buf1[10], 2, __builtin_object_size (&buf2[18], 0));
  __builtin___memmove_chk (&buf2[18], &buf1[10], 3, __builtin_object_size (&buf2[18], 0));
  __builtin___memset_chk (&buf2[16], 'a', 4, __builtin_object_size (&buf2[16], 0));
  __builtin___memset_chk (&buf2[15], 'b', 6, __builtin_object_size (&buf2[15], 0));
  __builtin___strcpy_chk (&buf2[18], "a", __builtin_object_size (&buf2[18], 0));
  __builtin___strcpy_chk (&buf2[18], "ab", __builtin_object_size (&buf2[18], 0));
  vx = __builtin___stpcpy_chk (&buf2[18], "a", __builtin_object_size (&buf2[18], 0));
  vx = __builtin___stpcpy_chk (&buf2[18], "ab", __builtin_object_size (&buf2[18], 0));
  __builtin___strncpy_chk (&buf2[18], "a", 2, __builtin_object_size (&buf2[18], 0));
  __builtin___strncpy_chk (&buf2[18], "a", 3, __builtin_object_size (&buf2[18], 0));
  __builtin___strncpy_chk (&buf2[18], "abc", 2, __builtin_object_size (&buf2[18], 0));
  __builtin___strncpy_chk (&buf2[18], "abc", 3, __builtin_object_size (&buf2[18], 0));
  __builtin___memset_chk (buf2, '\0', sizeof (buf2), __builtin_object_size (buf2, 0));
  __builtin___strcat_chk (&buf2[18], "a", __builtin_object_size (&buf2[18], 0));
  __builtin___memset_chk (buf2, '\0', sizeof (buf2), __builtin_object_size (buf2, 0));
  __builtin___strcat_chk (&buf2[18], "ab", __builtin_object_size (&buf2[18], 0));
  __builtin___sprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "%s", buf1);
  __builtin___sprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "%s", "a");
  __builtin___sprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "%s", "ab");
  __builtin___sprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "a");
  __builtin___sprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "ab");
  __builtin___snprintf_chk (&buf2[18], 2, 0, __builtin_object_size (&buf2[18], 0), "%d", x);




  __builtin___snprintf_chk (&buf2[18], 3, 0, __builtin_object_size (&buf2[18], 0), "%d", x);
  __builtin_va_start(ap, arg);
  __builtin___vsprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "a", ap);
  __builtin_va_end(ap);
  __builtin_va_start(ap, arg);
  __builtin___vsprintf_chk (&buf2[18], 0, __builtin_object_size (&buf2[18], 0), "ab", ap);
  __builtin_va_end(ap);
  __builtin_va_start(ap, arg);
  __builtin___vsnprintf_chk (&buf2[18], 2, 0, __builtin_object_size (&buf2[18], 0), "%s", ap);
  __builtin_va_end(ap);
  __builtin_va_start(ap, arg);

  __builtin___vsnprintf_chk (&buf2[18], 3, 0, __builtin_object_size (&buf2[18], 0), "%s", ap);
  __builtin_va_end(ap);

  p = p + 10;
  __builtin___memset_chk (p, 'd', 0, __builtin_object_size (p, 0));
  q = __builtin___strcpy_chk (p, "", __builtin_object_size (p, 0));


  p = p + 10;
  __builtin___memset_chk (p, 'd', 1, __builtin_object_size (p, 0));

  __builtin___memset_chk (q, 'd', 0, __builtin_object_size (q, 0));
  __builtin___memset_chk (q, 'd', 1, __builtin_object_size (q, 0));
  q = q - 10;
  __builtin___memset_chk (q, 'd', 10, __builtin_object_size (q, 0));
}

char *str = "ABCDEFG";
typedef struct { char b[16]; } H;




void
test2 (const H h)
{
  char c;
  __builtin___strncpy_chk (&c, str, 3, __builtin_object_size (&c, 0));

  struct { char b[4]; } x;
  __builtin___sprintf_chk (x.b, 0, __builtin_object_size (x.b, 0), "%s", "ABCD");

  unsigned int i;
  __builtin___memcpy_chk (&i, &h, sizeof (h), __builtin_object_size (&i, 0));

  unsigned char buf[21];
  __builtin___memset_chk (buf + 16, 0, 8, __builtin_object_size (buf + 16, 0));

  typedef struct { int i, j, k, l; } S;
  S *s[3];
  __builtin___memset_chk (s, 0, sizeof (S) * 3, __builtin_object_size (s, 0));

  struct T { char a[8]; char b[4]; char c[10]; } t;
  __builtin___stpcpy_chk (t.c, "Testing...", __builtin_object_size (t.c, 0));

  char b1[7];
  char b2[4];
  __builtin___memset_chk (b1, 0, sizeof (b1), __builtin_object_size (b1, 0));
  __builtin___memset_chk (b2, 0, sizeof (b1), __builtin_object_size (b2, 0));
}
