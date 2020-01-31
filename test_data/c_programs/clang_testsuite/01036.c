extern int tolower(int);
const char *rangematch(const char *pattern, int test, int c) {
  if ((c <= test) | (tolower(c) <= tolower((unsigned char)test)))
    return 0;
  return pattern;
}
