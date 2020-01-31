extern void a(const char *);
int main() {
  if (__builtin_cpu_supports("sse4.2"))
    a("sse4.2");
  return 0;
}
