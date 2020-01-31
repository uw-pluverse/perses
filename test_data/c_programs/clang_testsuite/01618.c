int scanf(const char * restrict, ...);
int printf(const char *restrict, ...);
void foo(char **sp, float *fp, int *ip) {
  scanf("%as", sp);
  scanf("%a[abc]", sp);
  scanf("%a", fp);
  scanf("%afoobar", fp);
  printf("%a", 1.0);
  printf("%as", 1.0);
  printf("%aS", 1.0);
  printf("%a[", 1.0);
  printf("%afoo", 1.0);
  scanf("%da", ip);
  scanf("%as", fp);
  scanf("%aS", fp);
  scanf("%a[abc]", fp);
}
