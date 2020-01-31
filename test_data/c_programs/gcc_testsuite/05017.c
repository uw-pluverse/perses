



void bar (char **);

__attribute__((nonnull (1, 3))) int
foo (char *cp1, char *cp2, char *cp3, char *cp4)
{
  if (cp1 == (char *) 0)
    return 1;

  cp1 = cp2;
  if (cp1 == (char *) 0)
    return 2;

  if (!cp4)
    return 3;

  char **p = &cp3;
  bar (p);
  if (cp3 == (char *) 0)
    return 4;

  return 5;
}
