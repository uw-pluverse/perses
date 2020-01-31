int f (int z)
{
   if (z > (int) sizeof (enum {a, b}))
      return a;
   return b;
}
