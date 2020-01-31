int *a, *b;

void
f ()
{
  while (a > b)
    {
      *a++ = *b++;
      *a++ = *b++;
      *a++ = *b++;
      *a++ = *b++;
    }
}
