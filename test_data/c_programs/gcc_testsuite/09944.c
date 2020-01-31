



extern void exit (int);
extern void longlong_i_doit (void);
extern void longlong_d_doit (void);
extern void complexint_i_doit (void);
extern void complexint_d_doit (void);
extern void complexdouble_i_doit (void);
extern void complexdouble_d_doit (void);
extern void complexlonglong_i_doit (void);
extern void complexlonglong_d_doit (void);

int main (void)
{
  longlong_i_doit ();
  longlong_d_doit ();


  complexint_i_doit ();
  complexint_d_doit ();

  complexdouble_i_doit ();
  complexdouble_d_doit ();

  complexlonglong_i_doit ();
  complexlonglong_d_doit ();


  exit (0);
}
