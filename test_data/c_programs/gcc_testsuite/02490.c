typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;






typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
typedef __loff_t loff_t;



typedef __ino_t ino_t;
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __ssize_t ssize_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef long unsigned int size_t;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;


extern void abort (void);

extern int inside_main;
void *chk_fail_buf[256] __attribute__((aligned (16)));
volatile int chk_fail_allowed, chk_calls;
volatile int memcpy_disallowed, mempcpy_disallowed, memmove_disallowed;
volatile int memset_disallowed, strcpy_disallowed, stpcpy_disallowed;
volatile int strncpy_disallowed, stpncpy_disallowed, strcat_disallowed;
volatile int strncat_disallowed, sprintf_disallowed, vsprintf_disallowed;
volatile int snprintf_disallowed, vsnprintf_disallowed;
extern long unsigned int strlen (const char *);
extern int vsprintf (char *, const char *, va_list);

void __attribute__((noreturn))
__chk_fail (void)
{
  if (chk_fail_allowed)
    __builtin_longjmp (chk_fail_buf, 1);
  abort ();
}

void *
memcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  while (n-- != 0)
    *dstp++ = *srcp++;

  return dst;
}

void *
__memcpy_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memcpy (dst, src, n);
}

void *
mempcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  while (n-- != 0)
    *dstp++ = *srcp++;

  return dstp;
}

void *
__mempcpy_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return mempcpy (dst, src, n);
}

void *
memmove (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  if (srcp < dstp)
    while (n-- != 0)
      dstp[n] = srcp[n];
  else
    while (n-- != 0)
      *dstp++ = *srcp++;

  return dst;
}

void *
__memmove_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memmove (dst, src, n);
}

void *
memset (void *dst, int c, long unsigned int n)
{
  while (n-- != 0)
    n[(char *) dst] = c;
  return dst;
}

void *
__memset_chk (void *dst, int c, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memset (dst, c, n);
}

char *
strcpy (char *d, const char *s)
{
  char *r = d;




  while ((*d++ = *s++));
  return r;
}

char *
__strcpy_chk (char *d, const char *s, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (s) >= size)
    __chk_fail ();
  return strcpy (d, s);
}

char *
stpcpy (char *dst, const char *src)
{





  while (*src != 0)
    *dst++ = *src++;

  *dst = 0;
  return dst;
}

char *
__stpcpy_chk (char *d, const char *s, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (s) >= size)
    __chk_fail ();
  return stpcpy (d, s);
}

char *
stpncpy (char *dst, const char *src, long unsigned int n)
{





  for (; *src && n; n--)
    *dst++ = *src++;

  char *ret = dst;

  while (n--)
    *dst++ = 0;

  return ret;
}


char *
__stpncpy_chk (char *s1, const char *s2, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return stpncpy (s1, s2, n);
}

char *
strncpy (char *s1, const char *s2, long unsigned int n)
{
  char *dest = s1;




  for (; *s2 && n; n--)
    *s1++ = *s2++;
  while (n--)
    *s1++ = 0;
  return dest;
}

char *
__strncpy_chk (char *s1, const char *s2, long unsigned int n, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return strncpy (s1, s2, n);
}

char *
strcat (char *dst, const char *src)
{
  char *p = dst;






  while (*p)
    p++;
  while ((*p++ = *src++))
    ;
  return dst;
}

char *
__strcat_chk (char *d, const char *s, long unsigned int size)
{

  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (d) + strlen (s) >= size)
    __chk_fail ();
  return strcat (d, s);
}

char *
strncat (char *s1, const char *s2, long unsigned int n)
{
  char *dest = s1;
  char c;




  while (*s1) s1++;
  c = '\0';
  while (n > 0)
    {
      c = *s2++;
      *s1++ = c;
      if (c == '\0')
 return dest;
      n--;
    }
  if (c != '\0')
    *s1 = '\0';
  return dest;
}

char *
__strncat_chk (char *d, const char *s, long unsigned int n, long unsigned int size)
{
  long unsigned int len = strlen (d), n1 = n;
  const char *s1 = s;


  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  while (len < size && n1 > 0)
    {
      if (*s1++ == '\0')
 break;
      ++len;
      --n1;
    }

  if (len >= size)
    __chk_fail ();
  return strncat (d, s, n);
}




static char chk_sprintf_buf[4096];

int
__sprintf_chk (char *str, int flag, long unsigned int size, const char *fmt, ...)
{
  int ret;
  va_list ap;



  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;




  __builtin_va_start(ap, fmt);
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  __builtin_va_end(ap);
  if (ret >= 0)
    {
      if (ret >= size)
 __chk_fail ();
      memcpy (str, chk_sprintf_buf, ret + 1);
    }
  return ret;
}

int
__vsprintf_chk (char *str, int flag, long unsigned int size, const char *fmt,
  va_list ap)
{
  int ret;



  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;




  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret >= size)
 __chk_fail ();
      memcpy (str, chk_sprintf_buf, ret + 1);
    }
  return ret;
}

int
__snprintf_chk (char *str, long unsigned int len, int flag, long unsigned int size,
  const char *fmt, ...)
{
  int ret;
  va_list ap;



  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;
  if (size < len)
    __chk_fail ();




  __builtin_va_start(ap, fmt);
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  __builtin_va_end(ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}

int
__vsnprintf_chk (char *str, long unsigned int len, int flag, long unsigned int size,
   const char *fmt, va_list ap)
{
  int ret;



  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;
  if (size < len)
    __chk_fail ();




  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}

int
snprintf (char *str, long unsigned int len, const char *fmt, ...)
{
  int ret;
  va_list ap;





  __builtin_va_start(ap, fmt);
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  __builtin_va_end(ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else if (len)
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}



int
vsnprintf (char *str, long unsigned int len, const char *fmt, va_list ap)
{
  int ret;





  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else if (len)
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}
