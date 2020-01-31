typedef long unsigned int size_t;
typedef signed ptrdiff_t;
typedef long long intmax_t;
typedef unsigned long long uintmax_t;
typedef void * FILE;
extern FILE *stdin;
extern int fscanf(FILE * restrict stream, const char * restrict format, ...);
extern int scanf(const char * restrict format, ...);
extern int sscanf(const char * restrict s, const char * restrict format, ...);
extern double atof(const char *nptr);
extern int atoi(const char *nptr);
extern long int atol(const char *nptr);
extern long long int atoll(const char *nptr);
void f1(const char *in) {
  int i;
  long long ll;
  unsigned int ui;
  unsigned long long ull;
  intmax_t im;
  uintmax_t uim;
  float f;
  double d;
  long double ld;
  sscanf(in, "%d", &i);
  fscanf(stdin, "%lld", &ll);
  sscanf(in, "%u", &ui);
  fscanf(stdin, "%llu", &ull);
  scanf("%jd", &im);
  fscanf(stdin, "%ju", &uim);
  sscanf(in, "%f", &f);
  fscanf(stdin, "%lg", &d);
  sscanf(in, "%Le", &ld);
  short s;
  char c;
  size_t st;
  ptrdiff_t pt;
  scanf("%hhd", &c);
  scanf("%hd", &s);
  scanf("%zu", &st);
  scanf("%td", &pt);
  scanf("%o", ui);
  scanf("%X", ui);
  scanf("%x", ui);
}
void f2(const char *in) {
  int i = atoi(in);
  long l = atol(in);
  long long ll = atoll(in);
  double d = atof(in);
}
void f3(void) {
  int i;
  unsigned int u;
  float f;
  char str[32];
  scanf("%d%u%f", &i, &u, &f);
  scanf("%s%d", str, &i);
}
void do_not_diagnose(void) {
  char str[32];
  scanf("%s", str);
  scanf("%*d");
}
