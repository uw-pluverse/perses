




extern void exit (int);
extern void longdouble_i_doit (void);
extern void longdouble_d_doit (void);

extern void complexlongdouble_i_doit (void);
extern void complexlongdouble_d_doit (void);


int main (void)
{
  longdouble_i_doit ();
  longdouble_d_doit ();

  complexlongdouble_i_doit ();
  complexlongdouble_d_doit ();

  exit (0);
}
