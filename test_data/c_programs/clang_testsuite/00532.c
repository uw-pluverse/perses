int main(int argc, char **argv) {
  int r;
#pragma omp target enter data
#pragma omp target enter data map(r)
#pragma omp target enter data map(tofrom: r)
#pragma omp target enter data map(always, to: r)
#pragma omp target enter data map(always, alloc: r)
#pragma omp target enter data map(always, from: r)
#pragma omp target enter data map(release: r)
#pragma omp target enter data map(delete: r)
  return 0;
}
