extern void link_error(void);

extern double pow(double,double);


int main()
{
  if (pow (2.0, 3.0) != 8.0)
    link_error ();

  if (pow (2.0, -3.0) != 0.125)
    link_error ();

  return 0;
}
