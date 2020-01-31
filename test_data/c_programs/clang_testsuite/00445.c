typedef struct _str {
  union {
    long double a;
    long c;
  };
} str;
void func(str s);
str ss;
void f9122143()
{
  func(ss);
}
