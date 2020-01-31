




extern void link_error0 (void);
extern void link_error1 (void);
extern void link_error2 (void);
extern void link_error3 (void);
extern void link_error4 (void);
extern void link_error5 (void);
extern void link_error6 (void);
extern void link_error7 (void);

extern int i;

extern int func0 (int) __attribute__ ((__pure__));
extern int func1 (int) __attribute__ ((__const__));



static int func2 (int a) { return i + a; }
static int func3 (int a) { return a * 3; }
static int func4 (int a) { return func0(a) + a; }
static int func5 (int a) { return a + func1(a); }
static int func6 (int a) { return func2(a) + a; }
static int func7 (int a) { return a + func3(a); }

int main ()
{
  int i[10], r;

  i[0] = 0;
  r = func0(0);
  if (i[0])
    link_error0();

  i[1] = 0;
  r = func1(0);
  if (i[1])
    link_error1();

  i[2] = 0;
  r = func2(0);
  if (i[2])
    link_error2();

  i[3] = 0;
  r = func3(0);
  if (i[3])
    link_error3();

  i[4] = 0;
  r = func4(0);
  if (i[4])
    link_error4();

  i[5] = 0;
  r = func5(0);
  if (i[5])
    link_error5();

  i[6] = 0;
  r = func6(0);
  if (i[6])
    link_error6();

  i[7] = 0;
  r = func7(0);
  if (i[7])
    link_error7();

  return r;
}

int func0 (int a) { return a - i; }
int func1 (int a) { return a - a; }

int i = 2;



void link_error0() {}
void link_error1() {}
void link_error2() {}
void link_error3() {}
void link_error4() {}
void link_error5() {}
void link_error6() {}
void link_error7() {}
