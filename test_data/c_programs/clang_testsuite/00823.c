typedef long unsigned int size_t;
void *memset(void*, int, size_t);
void bzero(void*, size_t);
void test(int* X, char *Y) {
  memset(X, 4, 1000);
  bzero(Y, 100);
}
