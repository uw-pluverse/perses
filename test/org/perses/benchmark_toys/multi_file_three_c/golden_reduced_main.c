int printf(const char *      , ...);
int compute_a(    );
int compute_b(    );
int main(    ) {
  int sum = compute_a() + compute_b();
  printf("sum = %d\n", sum);
}
