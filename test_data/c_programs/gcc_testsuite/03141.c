


extern int x;

unsigned
foo (unsigned int y)
{
  return (y << ((long int) &x)) | (y >> (32 - ((long int) &x)));
}
