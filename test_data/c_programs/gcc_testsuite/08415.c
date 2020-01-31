extern int strcmp (const char *, const char *);





extern void abort (void);






int main (int argc, char *argv[])
{

  char a[] = "foo@bar";

  if (strcmp (a, "foo@bar"))
    do { ; abort(); } while (0);

  return 0;
}
