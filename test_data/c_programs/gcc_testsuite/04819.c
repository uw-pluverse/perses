







void *memset (void *, int, long unsigned int);
void *malloc (long unsigned int);
void free (void *);





volatile int ten = 10;
int main(int argc, char **argv) {
  char *x = (char*)malloc(10);
  memset(x, 0, 10);
  int res = x[ten];
  free(x);
  return res;
}
