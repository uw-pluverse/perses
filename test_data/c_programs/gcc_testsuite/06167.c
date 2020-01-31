


extern void link_error (void);

int main (void)
{
  int exp = -1;

  if ((exp < 2 ? 2U : (unsigned int) exp) != 2)
    link_error ();
  return 0;
}
