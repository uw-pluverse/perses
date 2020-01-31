


double sin(double);
double floor(double);
float
t(float a)
{
 return sin(a);
}
float
q(float a)
{
 return floor(a);
}
double
q1(float a)
{
 return floor(a);
}
main()
{
 return 0;
}
__attribute__ ((weak))
double
floor(double a)
{
 abort ();
}
__attribute__ ((weak))
float
floorf(float a)
{
 return a;
}
__attribute__ ((weak))
double
sin(double a)
{
 return a;
}
__attribute__ ((weak))
float
sinf(float a)
{
 abort ();
}
