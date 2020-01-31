


int f(int i, unsigned j)
{
      int b[2];
      if (&b[i] == &b[j])
       return 1;
      return 0;
}
