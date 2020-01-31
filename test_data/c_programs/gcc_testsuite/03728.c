





static inline bar(const short int xs, const short int xe)
{
  if (xe && (xs < xe))
    ;
}

void f()
{
  short int xe;

  bar(0, xe);
}
