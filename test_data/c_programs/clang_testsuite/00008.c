typedef __typeof__(sizeof(int)) size_t;
typedef struct _IO_FILE FILE;
extern FILE *fopen(const char *path, const char *mode);
extern FILE *tmpfile(void);
extern int fclose(FILE *fp);
extern size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream);
extern void rewind (FILE *__stream);
void f1(void) {
  FILE *p = fopen("foo", "r");
  char buf[1024];
  fread(buf, 1, 1, p);
  fclose(p);
}
void f2(void) {
  FILE *p = fopen("foo", "r");
  fseek(p, 1, 0);
  fclose(p);
}
void f3(void) {
  FILE *p = fopen("foo", "r");
  ftell(p);
  fclose(p);
}
void f4(void) {
  FILE *p = fopen("foo", "r");
  rewind(p);
  fclose(p);
}
void f5(void) {
  FILE *p = fopen("foo", "r");
  if (!p)
    return;
  fseek(p, 1, 0);
  fseek(p, 1, 3);
  fclose(p);
}
void f6(void) {
  FILE *p = fopen("foo", "r");
  fclose(p);
  fclose(p);
}
void f7(void) {
  FILE *p = tmpfile();
  ftell(p);
  fclose(p);
}
void f8(int c) {
  FILE *p = fopen("foo.c", "r");
  if(c)
    return;
  fclose(p);
}
FILE *f9(void) {
  FILE *p = fopen("foo.c", "r");
  if (p)
    return p;
  else
    return 0;
}
void pr7831(FILE *fp) {
  fclose(fp);
}
void pr8081(FILE *stream, long offset, int whence) {
  fseek(stream, offset, whence);
}
