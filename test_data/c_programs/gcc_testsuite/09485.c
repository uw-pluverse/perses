



extern int sscanf (const char *restrict, const char *restrict, ...);
int *a;

void
foo ()
{
  sscanf (0, "0x%x  #", a);
}
