



double T,T2,E1[5];
int J;

void
PA(double E[])
{
 J = 0;

L10:
 E[1] = ( E[1] + E[2] + E[3] - E[4]) * T;
 E[2] = ( E[1] + E[2] - E[3] + E[4]) * T;
 E[3] = ( E[1] - E[2] + E[3] + E[4]) * T;
 E[4] = (-E[1] + E[2] + E[3] + E[4]) / T2;
 J += 1;

 if (J < 6)
  goto L10;
}
