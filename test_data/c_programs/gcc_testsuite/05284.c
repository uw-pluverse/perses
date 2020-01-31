

extern int printf (const char *, ...);
int foo(int argc, char **argv)
{
 int a;
 int b;
 int c;
 b = argc + 1;
 c = argc + 2;
 a = b + c;
 if (argc > 2)
 {
  c = argc + 3;
 }
 printf ("%d, %d\n", a, b + c);
}
