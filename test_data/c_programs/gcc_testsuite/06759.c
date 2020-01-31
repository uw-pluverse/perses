






typedef const struct __CFString *CFStringRef;







extern int cond;
extern const char *func(void);

CFStringRef s0 = ((CFStringRef) __builtin___CFStringMakeConstantString ("Hello" "there"));

void foo(void) {
  const CFStringRef s1 = ((CFStringRef) __builtin___CFStringMakeConstantString ("Str1"));

  s0 = s1;
}
