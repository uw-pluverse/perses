
int *f(int *a, int *b)
{
 *a = 1;
 *b = 2;
 int *c = a < b ? a : b;
 if (c)
   return c;
 else
   return a;
}
