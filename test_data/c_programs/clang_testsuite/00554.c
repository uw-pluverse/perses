typedef long unsigned int size_t;
double ceil(double x);
double copysign(double,double);
double cos(double x);
double fabs(double x);
double floor(double x);
char *strcat(char *s1, const char *s2);
char *strncat(char *s1, const char *s2, size_t n);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strcpy(char *s1, const char *s2);
char *stpcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t n);
size_t strlen(const char *s);
char *strpbrk(const char *s1, const char *s2);
size_t strspn(const char *s1, const char *s2);
double strtod(const char *nptr, char **endptr);
float strtof(const char *nptr, char **endptr);
long double strtold(const char *nptr, char **endptr);
long int strtol(const char *nptr, char **endptr, int base);
long long int strtoll(const char *nptr, char **endptr, int base);
unsigned long int strtoul(const char *nptr, char **endptr, int base);
unsigned long long int strtoull(const char *nptr, char **endptr, int base);
double t1(double x) { return ceil(x); }
double t2(double x, double y) { return copysign(x,y); }
double t3(double x) { return cos(x); }
double t4(double x) { return fabs(x); }
double t5(double x) { return floor(x); }
char *t6(char *x) { return strcat(x, ""); }
char *t7(char *x) { return strncat(x, "", 1); }
char *t8(void) { return strchr("hello, world", 'w'); }
char *t9(void) { return strrchr("hello, world", 'w'); }
int t10(void) { return strcmp("foo", "bar"); }
int t11(void) { return strncmp("foo", "bar", 3); }
char *t12(char *x) { return strcpy(x, "foo"); }
char *t13(char *x) { return stpcpy(x, "foo"); }
char *t14(char *x) { return strncpy(x, "foo", 3); }
size_t t15(void) { return strlen("foo"); }
char *t16(char *x) { return strpbrk(x, ""); }
size_t t17(char *x) { return strspn(x, ""); }
double t18(char **x) { return strtod("123.4", x); }
float t19(char **x) { return strtof("123.4", x); }
long double t20(char **x) { return strtold("123.4", x); }
long int t21(char **x) { return strtol("1234", x, 10); }
long int t22(char **x) { return strtoll("1234", x, 10); }
long int t23(char **x) { return strtoul("1234", x, 10); }
long int t24(char **x) { return strtoull("1234", x, 10); }
