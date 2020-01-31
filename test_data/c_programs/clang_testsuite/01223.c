extern int rand(void);
int nonrand();
int cTest() {
  int i = rand();
  int k = nonrand();
  return 0;
}
