typedef long unsigned int size_t;
size_t strlen (const char *s);
char *strncat(char *restrict s1, const char *restrict s2, size_t n);
struct {
  char f1[100];
  char f2[100][3];
} s4, **s5;
char s1[100];
char s2[200];
int x;
void test(char *src) {
  char dest[10];
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest) - strlen(dest) - 1);
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest) - 1);
  strncat(dest, src, sizeof(src));
  strncat(dest, src, sizeof(src) - 1);
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest));
  strncat(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sizeof(dest) - strlen(dest));
  strncat((*s5)->f2[x], s2, sizeof(s2));
  strncat(s1+3, s2, sizeof(s2));
  strncat(s4.f1, s2, sizeof(s2));
}
struct S {
  int y;
  char x[];
};
void flexible_arrays(struct S *s) {
  char str[] = "hi";
  strncat(s->x, str, sizeof(str));
}
void size_1() {
  char z[1];
  char str[] = "hi";
  strncat(z, str, sizeof(z));
}
void vlas(int size) {
  char z[size];
  char str[] = "hi";
  strncat(z, str, sizeof(str));
}
void f(char* s, char* d) {
  strncat(d, s, sizeof(d));
}
