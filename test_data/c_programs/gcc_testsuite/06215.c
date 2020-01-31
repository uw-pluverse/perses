


void foo();
void link_error (void);

int main()
{
  if (foo == (void *)0)
    link_error ();
  return 0;
}
