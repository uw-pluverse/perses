extern void abort (void);
extern int strcmp(const char *s1, const char *s2);
int q(int x) {return x + 40;}
int B(int x) {return x + 20;}
int foo(int x) {return x + 10;}
int bar(int x, int y) {return x + y;}
int baz(int x, int y) {return x + y;}
int toupper(int x) {return x + 32;}
int M(int x) {return x * 2;}

int main (int argc, char *argv[])
{

  if (q(2) != 42)
    do { ; abort(); } while (0);


  if (B(B(2)) != 42)
    do { ; abort(); } while (0);



  if (B(22) != 42)
    do { ; abort(); } while (0);



  if (5 + 37 != 42)
    do { ; abort(); } while (0);




  if (foo(bar(32, 0)) != 42)
    do { ; abort(); } while (0);
  if (foo(bar(32, 0)) != 42)
    do { ; abort(); } while (0);
  if (foo(foo(baz(22, 0))) != 42)
    do { ; abort(); } while (0);




  if (toupper (10) != 42)
    do { ; abort(); } while (0);






  if (2 + M(2 + M(9)) != 42)
    do { ; abort(); } while (0);






  if (1 + B(1 + B(0)) != 42)
    do { ; abort(); } while (0);



  {
    int insn = 6, i = 2, b = 2;


    if (((insn * 3 + 2) * i + 2) != 42)
      do { ; abort(); } while (0);
    if (((insn * 3 + 2) * i + 2) != 42)
      do { ; abort(); } while (0);


    if (((b * 4 + 2) * 4 + 2) != 42)
      do { ; abort(); } while (0);
  }




  if (strcmp ("forty", "forty"))
    do { ; abort(); } while (0);
  if (strcmp ("forty" "-two", "forty-two"))
    do { ; abort(); } while (0);


  if (42 != 42

      || 42 != 42

      || 42 != 42

      || 42



      != 42)
    do { ; abort(); } while (0);




  if (1 + q(1) != 42)
    do { ; abort(); } while (0);


  if (1 + 2 + 4 + 35 != 42)
    do { ; abort(); } while (0);


  return 0;
}
