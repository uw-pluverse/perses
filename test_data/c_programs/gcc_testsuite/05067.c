




extern long unsigned int strlen (const char *);

long unsigned int mystrlen (const char *s)
{
  if (!s)
    s = "";
  return strlen(s);
}
