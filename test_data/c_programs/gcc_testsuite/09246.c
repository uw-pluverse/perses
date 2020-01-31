


int
foo (_Bool a, _Bool b)
{
  return (a ^ (a == 0)) | ((b == 0) ^ b);
}
