int sprintf (char *s, const char *format, ...);

int foo(int i, int j)
{
   char *buf, *str;

   if (i)
     str = "";
   else if (j)
     str = "";
   else
     return 1;



   sprintf(buf, str);
   return 0;
}
