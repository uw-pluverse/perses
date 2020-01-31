




void bar (int, char *, char *, char *, char *, int);
void foo (int size)
{
  int i;
  for (i = 0; i < size; i++)
    {
      char temp[size];
      temp[size-1] = '\0';
      {
 char temp2[size];
 {
   char temp3[size];
   {
     char temp4[size];
     bar (i, temp, temp2, temp3, temp4, size);
   }
 }
      }
    }
}
