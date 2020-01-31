typedef int wchar_t;
typedef unsigned short char16_t;
typedef unsigned int char32_t;
void f() {
  char a1[] = "a";
  char a2[] = u8"a";
  char a3[] = u"a";
  char a4[] = U"a";
  char a5[] = L"a";
  wchar_t b1[] = "a";
  wchar_t b2[] = u8"a";
  wchar_t b3[] = u"a";
  wchar_t b4[] = U"a";
  wchar_t b5[] = L"a";
  char16_t c1[] = "a";
  char16_t c2[] = u8"a";
  char16_t c3[] = u"a";
  char16_t c4[] = U"a";
  char16_t c5[] = L"a";
  char32_t d1[] = "a";
  char32_t d2[] = u8"a";
  char32_t d3[] = u"a";
  char32_t d4[] = U"a";
  char32_t d5[] = L"a";
  int e1[] = "a";
  int e2[] = u8"a";
  int e3[] = u"a";
  int e4[] = U"a";
  int e5[] = L"a";
  long f1[] = "a";
  long f2[] = u8"a";
  long f3[] = u"a";
  long f4[] = U"a";
  long f5[] = L"a";
}
void g() {
  char a[] = 1;
  wchar_t b[] = 1;
  char16_t c[] = 1;
  char32_t d[] = 1;
}
