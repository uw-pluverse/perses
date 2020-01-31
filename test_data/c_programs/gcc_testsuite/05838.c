


double in;
extern void Write (double);
void foo (void)
{
  static double X[9];
  int i;
        X[1] = in * in;
        for (i = 2; i <= 8; i++)
            X[i] = X[i - 1] * X[1];
        Write (X[5]);
}
