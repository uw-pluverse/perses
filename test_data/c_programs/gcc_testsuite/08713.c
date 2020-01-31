




int global;

void __attribute__ ((noinline, noclone, used))
stuff (int i)
{
  global = i;
}

static void hooray ()
{
  stuff (1);
}

static void hiphip (void (*f)())
{
  stuff (2);
  f ();
}

int main (void)
{
  hiphip (hooray);
  return 0;
}
