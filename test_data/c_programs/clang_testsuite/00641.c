typedef struct _IO_FILE FILE;
extern FILE *stderr;
int fprintf(FILE * restrict stream, const char * restrict format, ...);
void test() {
  fprintf(stderr, "testing\n");
}
