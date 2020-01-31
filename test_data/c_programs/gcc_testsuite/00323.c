int sdat = 2;
const char sdat2[] = "1234";

const char * test (void)
{
  return sdat ? sdat2 : 0;
}
