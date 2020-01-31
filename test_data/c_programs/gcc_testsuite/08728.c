


static int x, y;

static __attribute__((noinline,noclone)) void
local (int *p)
{
  *p = 1;
}

static __attribute__((noinline,noclone)) void
local_address_taken (int *p)
{
  *p = 1;
}

void *anyfn_global;




void (*ex)(int *) = local_address_taken;

extern void link_error (void);

int main()
{
  void (*anyfn)(int *) = (void (*)(int *))(long unsigned int)anyfn_global;
  (*anyfn) (&x);
  x = 0;
  local (&y);


  if (x != 0)
    link_error ();
  x = 1;
  local_address_taken (&y);



  return x;
}
