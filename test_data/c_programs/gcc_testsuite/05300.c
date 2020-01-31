

void do_something1(void);
void do_something2(void);
void do_something3(void);
void do_something4(void);
void do_something5(void);
void do_something_big(int);

int do_something (int size)
{
  if (__builtin_constant_p (size))
    switch (size)
      {
 case 1:do_something1 (); break;
 case 2:do_something2 (); break;
 case 5:do_something1 (); do_something1 ();
 case 3:do_something3 (); break;
 case 4:do_something4 (); break;
      }
  else
    do_something_big (size);
}
extern int n;
int
main()
{
  do_something (2);
  do_something (3);
  do_something (5);
  do_something (70);
}
