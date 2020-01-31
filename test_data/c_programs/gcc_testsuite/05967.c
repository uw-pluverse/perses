


extern void link_error (void);



void foo (int testarray[])
{
  testarray[0] = 0;
  testarray[1] = 1;
  testarray[0]++;
  testarray[1]++;
  if (testarray[0] != 1)
    link_error ();
  if (testarray[1] != 2)
    link_error ();
}
