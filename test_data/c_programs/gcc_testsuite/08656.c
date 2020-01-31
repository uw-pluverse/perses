





int baz (int);

int foo ()
{
  return baz (baz (0));
}


int main ()
{
  return baz (baz (0));
}
