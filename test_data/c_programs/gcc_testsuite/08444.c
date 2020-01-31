extern void abort (void);
int main (int argc, char *argv[])
{
  double a = 5.;
  double x = .5;



  if (a != 5)
    do { ; abort(); } while (0);
  if (x != .5)

    do { ; abort(); } while (0);
  x = 25.6;


  if (x != 25.6)
    do { ; abort(); } while (0);



  if (250 != 25e+1 || 250 != 25e1 || 250 != 2500e-1)
    do { ; abort(); } while (0);




  return 0;
}
