
extern void abort (void);

int main ()
{


  int scale = (int) (unsigned char) -1 + 1;

  if ('ab' != (int) ((unsigned char) 'a' * scale + (unsigned char) 'b'))
    abort ();

  if ('\234b' != (int) ((unsigned char) '\234' * scale + (unsigned char) 'b'))
    abort ();

  if ('b\234' != (int) ((unsigned char) 'b' * scale + (unsigned char) '\234'))
    abort ();
  if ('\234aaa' > 0)
    abort ();
  return 0;
}
