extern long unsigned int strlen (const char *);

int i;

static void
SendEventProc (char *resultString)
{
  char *p;

  resultString = "";
  while (*p == '-')
    {
      if (p[2] == ' ')
 {
   resultString = p + 3;
 }
    }
  for (;;)
    {
      i = strlen (resultString) + 1;
    }
}
