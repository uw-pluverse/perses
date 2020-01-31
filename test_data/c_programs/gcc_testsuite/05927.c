


extern void link_error (void);



extern int not_returning (int) __attribute__ ((noreturn));

int b;
int test7 (int a)
{
  b = 7;
  if (a)
    {
      not_returning (a);
    }
  if (b != 7)
    link_error ();
  return b;
}
