



static int x0;
int static x1;

extern int x2;
int extern x3;

typedef int x4;
int typedef x5;

void g (int);

void
f (void)
{
  auto int x6 = 0;
  int auto x7 = 0;
  register int x8 = 0;
  int register x9 = 0;
  g (x6 + x7 + x8 + x9);
}

const static int x10;




__attribute__((format(printf, 1, 2))) static void h (const char *, ...);
__attribute__((format(printf, 1, 2))) void static i (const char *, ...);
