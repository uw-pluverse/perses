




extern int strcmp (const char *, const char *);





extern void abort (void);







int main (int argc, char *argv[])
{

  char a[] = "\"\\\"	\\\"\"";

  if (strcmp (a, "\"\\\"	\\\"\""))
    do { ; abort(); } while (0);

  return 0;
}
