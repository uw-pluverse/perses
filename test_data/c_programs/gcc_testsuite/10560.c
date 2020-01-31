



enum e
{
  a, b, c, d, e, f, g, h
};

int range1 (enum e v, int x)
{
  return x && v != c && v != d && v != e;
}

int range2 (enum e v, int x)
{
  return x && (v != c && v != d && v != e);
}
