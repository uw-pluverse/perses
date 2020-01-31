



void
foo (char *buf, unsigned long len)
{
  buf[0] = '\n';
  if (len > 1)
    buf[1] = '\0';

}
