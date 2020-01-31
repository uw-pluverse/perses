






int *foo (int *vector)
{
  return vector;
}

int *bar (int *vector __attribute__((unused)))
{
  return vector;
}

int *baz (int *vector __attribute__((unused)))
{
  return vector;
}
