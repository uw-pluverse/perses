



int foo ()
{
  int i, sum = 0, data[1024];

  for(i = 0; i<1024; i++)
    sum += data[i];

  return sum;
}
