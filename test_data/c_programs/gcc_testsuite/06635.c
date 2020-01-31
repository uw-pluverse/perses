unsigned long
wcscspn(const long *s, const long *set)
{
  const long *p;
  const long *q;

  p = s;
  while (*p)
    {
      q = set;
      while (*q)
        {
          if (*p == *q)
            goto done;
          q++;
        }
      p++;
    }

done:
  return (p - s);
}
