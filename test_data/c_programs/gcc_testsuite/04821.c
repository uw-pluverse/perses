



extern unsigned int a;

void
foo ()
{

  int d = __builtin_memcmp (&a, "123", 3);


  a = 1;
}
