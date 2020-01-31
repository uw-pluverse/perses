



int foo(long long a)
{
   if (a & (long long) 0x400)
      return 1;
   return 0;
}
