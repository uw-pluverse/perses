



extern int y(int *s3);

extern int s1, s2;

int x(void)
{
  int s3 = s1 + s2;
  return y(&s3);
}
