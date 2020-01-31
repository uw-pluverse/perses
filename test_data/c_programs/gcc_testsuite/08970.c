extern void abort (void);
extern int strcmp (const char *, const char *);

int
main (void)
{
  const char *t = "12";
  const char *u = "<:";
  if (strcmp (t, "1 %:%: 2") || strcmp (u, "<:"))
    abort ();
  else
    return 0;
}
