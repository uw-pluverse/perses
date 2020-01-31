


extern int a[];

void loop_clear (int i)
{
  while (i > 0)
    a[i--] = 0;
}
