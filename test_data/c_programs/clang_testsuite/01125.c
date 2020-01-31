typedef long unsigned int size_t;
size_t strlcpy (char * restrict dst, const char * restrict src, size_t size);
size_t strlcat (char * restrict dst, const char * restrict src, size_t size);
size_t strlen (const char *s);
char s1[100];
char s2[200];
char * s3;
struct {
  char f1[100];
  char f2[100][3];
} s4, **s5;
int x;
void f(void)
{
  strlcpy(s1, s2, sizeof(s1));
  strlcpy(s1, s2, sizeof(s2));
  strlcpy(s1, s3, strlen(s3)+1);
  strlcat(s2, s3, sizeof(s3));
  strlcpy(s4.f1, s2, sizeof(s2));
  strlcpy((*s5)->f2[x], s2, sizeof(s2));
  strlcpy(s1+3, s2, sizeof(s2));
}
struct S {
  int y;
  char x[];
};
void flexible_arrays(struct S *s) {
  char str[] = "hi";
  strlcpy(s->x, str, sizeof(str));
}
void size_1() {
  char z[1];
  char str[] = "hi";
  strlcpy(z, str, sizeof(str));
}
void vlas(int size) {
  char z[size];
  char str[] = "hi";
  strlcpy(z, str, sizeof(str));
}
