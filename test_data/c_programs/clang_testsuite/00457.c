int main(int argc, char **argv) {
  int r;
#pragma omp target exit data
#pragma omp target exit data map(r)
#pragma omp target exit data map(tofrom: r)
#pragma omp target exit data map(always, from: r)
#pragma omp target exit data map(delete: r)
#pragma omp target exit data map(release: r)
#pragma omp target exit data map(always, alloc: r)
#pragma omp target exit data map(to: r)
  return 0;
}
