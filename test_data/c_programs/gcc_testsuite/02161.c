





extern void abort (void);
float pinf;
float ninf;
float NaN;

int iuneq (float x, float y, int ok)
{
  if (((!((((x)) < ((y))) || ((x)) > ((y))))) != ok) abort ();;
  if ((!(((x) < (y)) || (x) > (y))) != ok) abort ();;
  if (((((x) <= (y)) || __builtin_isunordered ((x), (y))) && (((x) >= (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
}

int ieq (float x, float y, int ok)
{
  if (((((x) < (y)) || (x) >= (y)) && (!((((x)) < ((y))) || ((x)) > ((y))))) != ok) abort ();;
}

int iltgt (float x, float y, int ok)
{
  if ((!(!((((x)) < ((y))) || ((x)) > ((y))))) != ok) abort ();;
  if (((((x) < (y)) || (x) > (y))) != ok) abort ();;
  if (((((x) < (y)) || (x) >= (y)) && ((((x) < (y)) || __builtin_isunordered ((x), (y))) || (((x) > (y)) || __builtin_isunordered ((x), (y))))) != ok) abort ();;
}

int ine (float x, float y, int ok)
{
  if (((((x) < (y)) || __builtin_isunordered ((x), (y))) || (((x) > (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((x < y) || (x > y) || (!((((x)) < ((y))) || ((x)) >= ((y))))) != ok) abort ();;
}

int iunlt (float x, float y, int ok)
{
  if (((((x) < (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((!((((x)) < ((y))) || ((x)) >= ((y)))) || (x < y)) != ok) abort ();;
}

int ilt (float x, float y, int ok)
{
  if (((((x) < (y)) || (x) >= (y)) && (((x) < (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((x <= y) && (x != y)) != ok) abort ();;
  if (((x <= y) && (y != x)) != ok) abort ();;
  if (((x != y) && (x <= y)) != ok) abort ();;
  if (((y != x) && (x <= y)) != ok) abort ();;
}

int iunle (float x, float y, int ok)
{
  if (((((x) <= (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((!((((x)) < ((y))) || ((x)) >= ((y)))) || (x <= y)) != ok) abort ();;
}

int ile (float x, float y, int ok)
{
  if (((((x) < (y)) || (x) >= (y)) && (((x) <= (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((x < y) || (x == y)) != ok) abort ();;
  if (((y > x) || (x == y)) != ok) abort ();;
  if (((x == y) || (x < y)) != ok) abort ();;
  if (((y == x) || (x < y)) != ok) abort ();;
}

int iungt (float x, float y, int ok)
{
  if (((((x) > (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((!((((x)) < ((y))) || ((x)) >= ((y)))) || (x > y)) != ok) abort ();;
}

int igt (float x, float y, int ok)
{
  if (((((x) < (y)) || (x) >= (y)) && (((x) > (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((x >= y) && (x != y)) != ok) abort ();;
  if (((x >= y) && (y != x)) != ok) abort ();;
  if (((x != y) && (x >= y)) != ok) abort ();;
  if (((y != x) && (x >= y)) != ok) abort ();;
}

int iunge (float x, float y, int ok)
{
  if (((((x) >= (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((!((((x)) < ((y))) || ((x)) >= ((y)))) || (x >= y)) != ok) abort ();;
}

int ige (float x, float y, int ok)
{
  if (((((x) < (y)) || (x) >= (y)) && (((x) >= (y)) || __builtin_isunordered ((x), (y)))) != ok) abort ();;
  if (((x > y) || (x == y)) != ok) abort ();;
  if (((y < x) || (x == y)) != ok) abort ();;
  if (((x == y) || (x > y)) != ok) abort ();;
  if (((y == x) || (x > y)) != ok) abort ();;
}

int
main ()
{
  pinf = __builtin_inf ();
  ninf = -__builtin_inf ();
  NaN = __builtin_nan ("");

  iuneq (ninf, pinf, 0);
  iuneq (NaN, NaN, 1);
  iuneq (pinf, ninf, 0);
  iuneq (1, 4, 0);
  iuneq (3, 3, 1);
  iuneq (5, 2, 0);

  ieq (1, 4, 0);
  ieq (3, 3, 1);
  ieq (5, 2, 0);

  iltgt (ninf, pinf, 1);
  iltgt (NaN, NaN, 0);
  iltgt (pinf, ninf, 1);
  iltgt (1, 4, 1);
  iltgt (3, 3, 0);
  iltgt (5, 2, 1);

  ine (1, 4, 1);
  ine (3, 3, 0);
  ine (5, 2, 1);

  iunlt (NaN, ninf, 1);
  iunlt (pinf, NaN, 1);
  iunlt (pinf, ninf, 0);
  iunlt (pinf, pinf, 0);
  iunlt (ninf, ninf, 0);
  iunlt (1, 4, 1);
  iunlt (3, 3, 0);
  iunlt (5, 2, 0);

  ilt (1, 4, 1);
  ilt (3, 3, 0);
  ilt (5, 2, 0);

  iunle (NaN, ninf, 1);
  iunle (pinf, NaN, 1);
  iunle (pinf, ninf, 0);
  iunle (pinf, pinf, 1);
  iunle (ninf, ninf, 1);
  iunle (1, 4, 1);
  iunle (3, 3, 1);
  iunle (5, 2, 0);

  ile (1, 4, 1);
  ile (3, 3, 1);
  ile (5, 2, 0);

  iungt (NaN, ninf, 1);
  iungt (pinf, NaN, 1);
  iungt (pinf, ninf, 1);
  iungt (pinf, pinf, 0);
  iungt (ninf, ninf, 0);
  iungt (1, 4, 0);
  iungt (3, 3, 0);
  iungt (5, 2, 1);

  igt (1, 4, 0);
  igt (3, 3, 0);
  igt (5, 2, 1);

  iunge (NaN, ninf, 1);
  iunge (pinf, NaN, 1);
  iunge (ninf, pinf, 0);
  iunge (pinf, pinf, 1);
  iunge (ninf, ninf, 1);
  iunge (1, 4, 0);
  iunge (3, 3, 1);
  iunge (5, 2, 1);

  ige (1, 4, 0);
  ige (3, 3, 1);
  ige (5, 2, 1);

  return 0;
}
