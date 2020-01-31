






void
foo ( const char *bytes, int len , char *buf)
{
  int i;
  for ( i = 0; i < len; ++i )
    buf[i] = bytes[i];
}
