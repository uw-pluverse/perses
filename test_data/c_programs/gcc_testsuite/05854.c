

int
t(char *a)
{
 static char p[100];
 if (a)
  return t(p);
 else
  return 0;
}
