_Static_assert(sizeof(long) == 4, "sizeof long is wrong");
_Static_assert(_Alignof(long) == 4, "sizeof long is wrong");
long test_long(long v) {
  return v + 1;
}
typedef struct {char c1, c2, c3; } sChar3;
typedef struct {short s; char c;} sShortChar;
void argChar3(sChar3 s) {}
void argShortChar(sShortChar s) {}
sChar3 retChar3() { sChar3 r; return r; }
sShortChar retShortChar() { sShortChar r; return r; }
typedef struct {short s1; char c; short s2; } sShortCharShort;
typedef struct {int i; short s; char c; } sIntShortChar;
typedef struct {long l; int i; } sLongInt;
void argShortCharShort(sShortCharShort s) {}
void argIntShortChar(sIntShortChar s) {}
void argLongInt(sLongInt s) {}
sShortCharShort retShortCharShort() { sShortCharShort r; return r; }
sIntShortChar retIntShortChar() { sIntShortChar r; return r; }
sLongInt retLongInt() { sLongInt r; return r; }
typedef struct {int i1, i2, i3, i4, i5; } sInt5;
typedef struct {long l1, l2; char c; } sLong2Char;
void argInt5(sInt5 s) {}
void argLong2Char(sLong2Char s) {}
sInt5 retInt5() { sInt5 r; return r;}
sLong2Char retLong2Char() { sLong2Char r; return r;}
typedef struct {long l1, l2, l3, l4, l5, l6, l7, l8, l9; } sLong9;
void argLong9(sLong9 s) {}
sLong9 retLong9() { sLong9 r; return r; }
