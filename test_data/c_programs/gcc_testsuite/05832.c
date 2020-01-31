


extern void link_error (void);



void foo (int testarray[])
{
  testarray[0] = 0;
  testarray[0]++;
  if (testarray[0] != 1)
    link_error ();
}
