unsigned long long int badshift(unsigned long long int v)
{
        return v << 31 << 1;
}

extern void abort ();

int main() {
  if (badshift (1) == 0)
    abort ();
  return 0;
}
