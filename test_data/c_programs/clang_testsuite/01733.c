void foo(int *a, int *b) {
#pragma omp target map(a[0:N]) map_to_be_expanded(b[0:2*M])
  {
    int reda;
    int redb;
#pragma omp parallel for sched_to_be_expanded(static, E>1) reda_to_be_expanded(reda) redb_to_be_expanded(redb,*)
    for (int i = 0; i < 2; ++i) {
      reda += a[i];
      redb += b[i];
    }
    a[0] = reda;
    b[0] = redb;
  }
}
