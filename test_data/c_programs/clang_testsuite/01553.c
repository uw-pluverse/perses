struct a x1;
static struct a x2;
struct a x3[10];
struct a {int x;};
static struct a x2_okay;
struct a x3_okay[10];
struct b x4;
const int a [1] = {1};
extern const int a[];
extern const int b[];
const int b [1] = {1};
extern const int c[] = {1};
const int c[];
int i1 = 1;
int i1 = 2;
int i1;
int i1;
extern int i5;
static int i5;
static int i2 = 5;
int i2 = 3;
static int i3 = 5;
extern int i3;
__private_extern__ int pExtern;
int pExtern = 0;
int i4;
int i4;
extern int i4;
int (*pToArray)[];
int (*pToArray)[8];
int redef[10];
int redef[];
int redef[11];
void func() {
  extern int i6;
  static int i6;
}
void func2(void)
{
  extern double *p;
  extern double *p;
}
static int a0[];
static int b0;
static int a0[] = { 4 };
static int b0 = 5;
