


char *p;

int main()
{
  p = "";
  if (p[0] == 0
      || (p[0] == '_' && p[1] == 0))
    return 0;
  return 1;
}
