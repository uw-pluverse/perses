




void bar (char *, char *, char *, char *, int);
void foo (int size)
{
  char temp[size];
  temp[size-1] = '\0';
  {
    char temp2[size];
    {
      char temp3[size];
      {
 char temp4[size];
 bar (temp, temp2, temp3, temp4, size);
      }
    }
    bar (temp, temp2, (char *) 0, (char *) 0, size);
  }
}
