
union U
{
  const int a;
  unsigned b : 24;
};

static union U u = { 0x12345678 };




int
main (void)
{


  return u.b - 0x345678;




  return 0;
}
