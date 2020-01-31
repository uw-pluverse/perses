


extern void abort (void);


extern void *chk_fail_buf[];
extern volatile int chk_fail_allowed, chk_calls;
extern volatile int memcpy_disallowed, mempcpy_disallowed, memmove_disallowed;
extern volatile int memset_disallowed, strcpy_disallowed, stpcpy_disallowed;
extern volatile int strncpy_disallowed, stpncpy_disallowed, strcat_disallowed;
extern volatile int strncat_disallowed, sprintf_disallowed, vsprintf_disallowed;
extern volatile int snprintf_disallowed, vsnprintf_disallowed;

extern char *mallocminus1(int size) __attribute__((alloc_size(-1)));
extern char *malloc0(int size) __attribute__((alloc_size(0)));
extern char *malloc1(int size) __attribute__((alloc_size(1)));
extern char *malloc2(int empty, int size) __attribute__((alloc_size(2)));
extern char *calloc1(int size, int elements) __attribute__((alloc_size(1,2)));
extern char *calloc2(int size, int empty, int elements) __attribute__((alloc_size(1,3)));
extern char *balloc1(void *size) __attribute__((alloc_size(1)));

void
test (void)
{
  char *p;

  p = malloc0 (6);
  __builtin___strcpy_chk (p, "Hello", __builtin_object_size (p, 0));
  p = malloc1 (6);
  __builtin___strcpy_chk (p, "Hello", __builtin_object_size (p, 0));
  __builtin___strcpy_chk (p, "Hello World", __builtin_object_size (p, 0));
  p = malloc2 (2147483647 >= 1700000 ? 424242 : 2147483647 / 4, 6);
  __builtin___strcpy_chk (p, "World", __builtin_object_size (p, 0));
  __builtin___strcpy_chk (p, "Hello World", __builtin_object_size (p, 0));
  p = calloc1 (2, 5);
  __builtin___strcpy_chk (p, "World", __builtin_object_size (p, 0));
  __builtin___strcpy_chk (p, "Hello World", __builtin_object_size (p, 0));
  p = calloc2 (2, 2147483647 >= 1700000 ? 424242 : 2147483647 / 4, 5);
  __builtin___strcpy_chk (p, "World", __builtin_object_size (p, 0));
  __builtin___strcpy_chk (p, "Hello World", __builtin_object_size (p, 0));
}
