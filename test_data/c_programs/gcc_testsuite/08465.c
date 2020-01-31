






extern void abort (void);
int
main(void)
{
  unsigned int five = 0;




   five++;


   five++;


   five++;


   five++;


   five++;

  if (five != 5)
    abort ();
  return 0;
}
