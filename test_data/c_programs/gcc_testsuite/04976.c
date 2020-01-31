



__attribute__((vector (vectorlength(128))))

int func2 (int x, int y)
{
  return (x+y);
}

int main (void)
{
  return (func2 (5,6));
}
