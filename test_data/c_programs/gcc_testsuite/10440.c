






extern void abort(void);






#pragma options 23
#pragma options align
#pragma options align natural
#pragma options align=45
#pragma options align=foo





#pragma options align=power
struct s2 { short f1; int f2; };




#pragma options align=reset
struct s4 { short f1; int f2; };

#pragma options align=natural foo




#pragma segment foo

int
main ()
{
  int x, z;
#pragma unused (x, y)





 if (sizeof (struct s2) != 8)
    abort ();




  if (sizeof (struct s4) != 8)
    abort ();
  return 0;
}

void
unused_err_test ()
{
  int a, b;

#pragma unused
#pragma unused (a
#pragma unused (b) foo
}
