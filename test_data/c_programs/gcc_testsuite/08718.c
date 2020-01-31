




extern void non_existent(int);

static void hooray ()
{
  non_existent (1);
}

static void hiphip (void (*f)())
{
  non_existent (2);
  f ();
}

int test (void)
{
  hiphip (hooray);
  return 0;
}
