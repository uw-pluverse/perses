int
func (int b)
{
  if (((&b) != ((void *) 0) ? 0 : (&b)) > 0)
    return 1;
  if (((&b) == ((void *) 0) ? 0 : (&b)) > 0)
    return 2;
  if ((((void *) 0) != (&b) ? 0 : (&b)) > 0)
    return 3;
  if ((((void *) 0) == (&b) ? 0 : (&b)) > 0)
    return 4;
  return 0;
}
