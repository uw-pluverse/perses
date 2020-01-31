


int main(void)
{
  unsigned i, j;

  for (i = 1, j = 0; i != 0; i+=2)
    {
      j += 500;
      if (j % 7)
 {
   j++;
 }
      else
 {
   j--;
 }
    }

  return 0;
}
