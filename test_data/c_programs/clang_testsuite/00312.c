extern unsigned UnsignedErrorCode;
extern unsigned long UnsignedLongErrorCode;
extern unsigned long long UnsignedLongLongErrorCode;
extern int IntErrorCode;
extern long LongErrorCode;
extern long long LongLongErrorCode;
void overflowed(void);
unsigned test_add_overflow_uint_uint_uint(unsigned x, unsigned y) {
  unsigned r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
int test_add_overflow_int_int_int(int x, int y) {
  int r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
unsigned test_sub_overflow_uint_uint_uint(unsigned x, unsigned y) {
  unsigned r;
  if (__builtin_sub_overflow(x, y, &r))
    overflowed();
  return r;
}
int test_sub_overflow_int_int_int(int x, int y) {
  int r;
  if (__builtin_sub_overflow(x, y, &r))
    overflowed();
  return r;
}
unsigned test_mul_overflow_uint_uint_uint(unsigned x, unsigned y) {
  unsigned r;
  if (__builtin_mul_overflow(x, y, &r))
    overflowed();
  return r;
}
int test_mul_overflow_int_int_int(int x, int y) {
  int r;
  if (__builtin_mul_overflow(x, y, &r))
    overflowed();
  return r;
}
int test_add_overflow_uint_int_int(unsigned x, int y) {
  int r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
_Bool test_add_overflow_uint_uint_bool(unsigned x, unsigned y) {
  _Bool r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
unsigned test_add_overflow_bool_bool_uint(_Bool x, _Bool y) {
  unsigned r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
_Bool test_add_overflow_bool_bool_bool(_Bool x, _Bool y) {
  _Bool r;
  if (__builtin_add_overflow(x, y, &r))
    overflowed();
  return r;
}
int test_add_overflow_volatile(int x, int y) {
  volatile int result;
  if (__builtin_add_overflow(x, y, &result))
    overflowed();
  return result;
}
unsigned test_uadd_overflow(unsigned x, unsigned y) {
  unsigned result;
  if (__builtin_uadd_overflow(x, y, &result))
    return UnsignedErrorCode;
  return result;
}
unsigned long test_uaddl_overflow(unsigned long x, unsigned long y) {
  unsigned long result;
  if (__builtin_uaddl_overflow(x, y, &result))
    return UnsignedLongErrorCode;
  return result;
}
unsigned long long test_uaddll_overflow(unsigned long long x, unsigned long long y) {
  unsigned long long result;
  if (__builtin_uaddll_overflow(x, y, &result))
    return UnsignedLongLongErrorCode;
  return result;
}
unsigned test_usub_overflow(unsigned x, unsigned y) {
  unsigned result;
  if (__builtin_usub_overflow(x, y, &result))
    return UnsignedErrorCode;
  return result;
}
unsigned long test_usubl_overflow(unsigned long x, unsigned long y) {
  unsigned long result;
  if (__builtin_usubl_overflow(x, y, &result))
    return UnsignedLongErrorCode;
  return result;
}
unsigned long long test_usubll_overflow(unsigned long long x, unsigned long long y) {
  unsigned long long result;
  if (__builtin_usubll_overflow(x, y, &result))
    return UnsignedLongLongErrorCode;
  return result;
}
unsigned test_umul_overflow(unsigned x, unsigned y) {
  unsigned result;
  if (__builtin_umul_overflow(x, y, &result))
    return UnsignedErrorCode;
  return result;
}
unsigned long test_umull_overflow(unsigned long x, unsigned long y) {
  unsigned long result;
  if (__builtin_umull_overflow(x, y, &result))
    return UnsignedLongErrorCode;
  return result;
}
unsigned long long test_umulll_overflow(unsigned long long x, unsigned long long y) {
  unsigned long long result;
  if (__builtin_umulll_overflow(x, y, &result))
    return UnsignedLongLongErrorCode;
  return result;
}
int test_sadd_overflow(int x, int y) {
  int result;
  if (__builtin_sadd_overflow(x, y, &result))
    return IntErrorCode;
  return result;
}
long test_saddl_overflow(long x, long y) {
  long result;
  if (__builtin_saddl_overflow(x, y, &result))
    return LongErrorCode;
  return result;
}
long long test_saddll_overflow(long long x, long long y) {
  long long result;
  if (__builtin_saddll_overflow(x, y, &result))
    return LongLongErrorCode;
  return result;
}
int test_ssub_overflow(int x, int y) {
  int result;
  if (__builtin_ssub_overflow(x, y, &result))
    return IntErrorCode;
  return result;
}
long test_ssubl_overflow(long x, long y) {
  long result;
  if (__builtin_ssubl_overflow(x, y, &result))
    return LongErrorCode;
  return result;
}
long long test_ssubll_overflow(long long x, long long y) {
  long long result;
  if (__builtin_ssubll_overflow(x, y, &result))
    return LongLongErrorCode;
  return result;
}
int test_smul_overflow(int x, int y) {
  int result;
  if (__builtin_smul_overflow(x, y, &result))
    return IntErrorCode;
  return result;
}
long test_smull_overflow(long x, long y) {
  long result;
  if (__builtin_smull_overflow(x, y, &result))
    return LongErrorCode;
  return result;
}
long long test_smulll_overflow(long long x, long long y) {
  long long result;
  if (__builtin_smulll_overflow(x, y, &result))
    return LongLongErrorCode;
  return result;
}
