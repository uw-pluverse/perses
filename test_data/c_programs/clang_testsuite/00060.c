typedef long unsigned int size_t;
char *strncat(char *, const char *, size_t);
size_t strlen (const char *s);
void testStrncat(const char *src) {
  char dest[10];
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest) - 1);
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest));
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest) - strlen(dest));
  strncat(dest, src, sizeof(src));
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(char));
}
