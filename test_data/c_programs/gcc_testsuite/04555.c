



int
main (void)
{
  const long double inf = __builtin_infl ();
  const long double nan = __builtin_nanl ("");
  volatile long double ld;

  volatile int i;
  ld = (-2147483647 -1);
  (i) = (ld) - 5.0; (i) = (ld) - 1.5; (i) = (ld) - 1.0; (i) = (ld) - 0.75; (i) = (ld) - 0.5; (i) = (ld) - 0.0000001; (i) = (ld) - 0.0; (i) = (ld); (i) = (ld) + 0.0; (i) = (ld) + 0.0000001; (i) = (ld) + 0.5; (i) = (ld) + 0.75; (i) = (ld) + 1.0; (i) = (ld) + 1.5; (i) = (ld) + 5.0;;
  ld = 0.0l;
  (i) = (ld) - 5.0; (i) = (ld) - 1.5; (i) = (ld) - 1.0; (i) = (ld) - 0.75; (i) = (ld) - 0.5; (i) = (ld) - 0.0000001; (i) = (ld) - 0.0; (i) = (ld); (i) = (ld) + 0.0; (i) = (ld) + 0.0000001; (i) = (ld) + 0.5; (i) = (ld) + 0.75; (i) = (ld) + 1.0; (i) = (ld) + 1.5; (i) = (ld) + 5.0;;
  ld = 2147483647;
  (i) = (ld) - 5.0; (i) = (ld) - 1.5; (i) = (ld) - 1.0; (i) = (ld) - 0.75; (i) = (ld) - 0.5; (i) = (ld) - 0.0000001; (i) = (ld) - 0.0; (i) = (ld); (i) = (ld) + 0.0; (i) = (ld) + 0.0000001; (i) = (ld) + 0.5; (i) = (ld) + 0.75; (i) = (ld) + 1.0; (i) = (ld) + 1.5; (i) = (ld) + 5.0;;
  (i) = nan; (i) = -nan; (i) = inf; (i) = -inf;;

  volatile unsigned int u;
  ld = (2147483647 *2U +1U);
  (u) = (ld) - 5.0; (u) = (ld) - 1.5; (u) = (ld) - 1.0; (u) = (ld) - 0.75; (u) = (ld) - 0.5; (u) = (ld) - 0.0000001; (u) = (ld) - 0.0; (u) = (ld); (u) = (ld) + 0.0; (u) = (ld) + 0.0000001; (u) = (ld) + 0.5; (u) = (ld) + 0.75; (u) = (ld) + 1.0; (u) = (ld) + 1.5; (u) = (ld) + 5.0;;
  ld = 0.0l;
  (u) = (ld) - 5.0; (u) = (ld) - 1.5; (u) = (ld) - 1.0; (u) = (ld) - 0.75; (u) = (ld) - 0.5; (u) = (ld) - 0.0000001; (u) = (ld) - 0.0; (u) = (ld); (u) = (ld) + 0.0; (u) = (ld) + 0.0000001; (u) = (ld) + 0.5; (u) = (ld) + 0.75; (u) = (ld) + 1.0; (u) = (ld) + 1.5; (u) = (ld) + 5.0;;
  (u) = nan; (u) = -nan; (u) = inf; (u) = -inf;;

  return 0;
}
