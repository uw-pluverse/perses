




static __thread void *baz [4] __attribute__((tls_model ("initial-exec")));
void foo (void)
{
  void **u = (void **) baz;

  u[0] = 0;
  u[1] = 0;
}
