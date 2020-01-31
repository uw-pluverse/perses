typedef signed long CFIndex;
typedef const struct __CFAllocator * CFAllocatorRef;
enum { kCFNumberSInt8Type = 1, kCFNumberSInt16Type = 2,
       kCFNumberSInt32Type = 3, kCFNumberSInt64Type = 4,
       kCFNumberFloat32Type = 5, kCFNumberFloat64Type = 6,
       kCFNumberCharType = 7, kCFNumberShortType = 8,
       kCFNumberIntType = 9, kCFNumberLongType = 10,
       kCFNumberLongLongType = 11, kCFNumberFloatType = 12,
       kCFNumberDoubleType = 13, kCFNumberCFIndexType = 14,
       kCFNumberNSIntegerType = 15, kCFNumberCGFloatType = 16,
       kCFNumberMaxType = 16 };
typedef CFIndex CFNumberType;
typedef const struct __CFNumber * CFNumberRef;
typedef unsigned char Boolean;
extern CFNumberRef CFNumberCreate(CFAllocatorRef allocator, CFNumberType theType, const void *valuePtr);
Boolean CFNumberGetValue(CFNumberRef number, CFNumberType theType, void *valuePtr);
__attribute__((cf_returns_retained)) CFNumberRef f1(unsigned char x) {
  return CFNumberCreate(0, kCFNumberSInt16Type, &x);
}
__attribute__((cf_returns_retained)) CFNumberRef f2(unsigned short x) {
  return CFNumberCreate(0, kCFNumberSInt8Type, &x);
}
__attribute__((cf_returns_not_retained)) CFNumberRef CreateNum(unsigned char x) {
  return CFNumberCreate(0, kCFNumberSInt8Type, &x);
}
__attribute__((cf_returns_retained)) CFNumberRef f3(unsigned i) {
  return CFNumberCreate(0, kCFNumberLongType, &i);
}
unsigned char getValueTest1(CFNumberRef x) {
  unsigned char scalar = 0;
  CFNumberGetValue(x, kCFNumberSInt16Type, &scalar);
  return scalar;
}
unsigned char getValueTest2(CFNumberRef x) {
  unsigned short scalar = 0;
  CFNumberGetValue(x, kCFNumberSInt8Type, &scalar);
  return scalar;
}
