





extern void bar(void);

int foo(int x, int y, unsigned u)
{


  if (u < ((x=-22)/33))
    return x;

  if (u < ((x=22)/33))
    return x;

  if (u < ((x=22)/(y=33)))
    return x;

  if (u < (((x&0x10000)?128:64) / ((y&0x10000)?8:4)))
    return x;




  if (u < ((x=-22)%33))
    return x;

  if (u < ((x=22)%-33))
    return x;

  if (u < ((x==y)%-33))
    return x;

  if (u < (((x=22)/33)%-33))
    return x;

  return 0;
}
