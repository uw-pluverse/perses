int printf(char const *, ...);
int scanf(char const *, ...);
void pr9751() {
  const char kFormat1[] = "%s";
  printf(kFormat1, 5);
  printf("%s", 5);
  const char kFormat2[] = "%.3p";
  void *p;
  printf(kFormat2, p);
  printf("%.3p", p);
  const char kFormat3[] = "%0s";
  printf(kFormat3, "a");
  printf("%0s", "a");
  const char kFormat4[] = "%hhs";
  printf(kFormat4, "a");
  printf("%hhs", "a");
  const char kFormat5[] = "%-0d";
  printf(kFormat5, 5);
  printf("%-0d", 5);
  const char kFormat6[] = "%00d";
  int *i;
  scanf(kFormat6, i);
  scanf("%00d", i);
}
