

int
foo ()
{
  extern long long Y;
  return (0 > Y++);
}
