typedef enum CCTestEnum
{
  One,
  Two=4,
  Three
} CCTestEnum;
CCTestEnum test = 50;
CCTestEnum test1 = -50;
static const CCTestEnum SilenceWithCast1 = 51;
static const CCTestEnum SilenceWithCast2 = (CCTestEnum) 51;
static const CCTestEnum SilenceWithCast3 = (const CCTestEnum) 51;
static const CCTestEnum SilenceWithCast4 = (const volatile CCTestEnum) 51;
void SilenceWithCastLocalVar() {
  CCTestEnum SilenceWithCast1 = 51;
  CCTestEnum SilenceWithCast2 = (CCTestEnum) 51;
  CCTestEnum SilenceWithCast3 = (const CCTestEnum) 51;
  CCTestEnum SilenceWithCast4 = (const volatile CCTestEnum) 51;
  const CCTestEnum SilenceWithCast1c = 51;
  const CCTestEnum SilenceWithCast2c = (CCTestEnum) 51;
  const CCTestEnum SilenceWithCast3c = (const CCTestEnum) 51;
  const CCTestEnum SilenceWithCast4c = (const volatile CCTestEnum) 51;
}
CCTestEnum foo(CCTestEnum r) {
  return 20;
}
enum Test2 { K_zero, K_one };
enum Test2 test2(enum Test2 *t) {
  *t = 20;
  return 10;
}
typedef enum
{
  a = 0
} T;
void f()
{
  T x = a;
  x += 1;
}
int main() {
  CCTestEnum test = 1;
  test = 600;
  foo(2);
  foo(-1);
  foo(4);
  foo(Two+1);
}
