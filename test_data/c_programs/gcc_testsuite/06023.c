


int foo(unsigned int cc )
{

  while ( cc >> 16 )
    {
      cc = (cc & 0xffff) + (cc >> 16);
    }

  return ( (unsigned short)(cc) ) == ((unsigned short)(-1));
}
