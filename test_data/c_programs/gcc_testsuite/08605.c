




_Bool f();
void g(int);
void h (int old_size)
{
   int new_size = old_size, i;
   g(old_size - 1);
   i = 0;
   while (i < old_size - 1)
   {
     if (f())
     {
       i++;
       continue;
     }
     while (i < old_size - 1)
       i++;
   }
   g(new_size);
}
