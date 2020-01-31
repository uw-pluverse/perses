extern void a(const char *);
extern const char *str;
int main() {
  if (__builtin_cpu_supports("ss"))
    a("sse4.2");
  if (__builtin_cpu_supports(str))
    a(str);
  return 0;
}
