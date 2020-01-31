




int a;
static int b;
extern int c;
void f0(void);
static void f1(void);

void
g(void)
{
  extern int a;
  extern int b;
  extern int c;
  extern int d;
  extern void f0(void);
  extern void f1(void);
  extern void f2(void);
}
