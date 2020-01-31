




extern int __attribute__ ((noinline, noclone, used))
stuff (int i)
{
  return 0;
}

static void hooray ()
{
  stuff (1);
}

static int hiphip (void (*f)())
{
  return stuff (2);
}

int main (void)
{
  return hiphip (hooray);
}
