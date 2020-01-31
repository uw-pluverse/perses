



extern unsigned int a;

void
foo ()
{

  int d = __builtin_memcmp (&a, "12345", 4);



  a = 1;
}
