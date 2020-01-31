




struct s {
  unsigned int pad1 : 3;
  unsigned int bitfield : 20;
  unsigned int intfield;
};

void f (struct s *a, struct s *b)
{
  a->bitfield = b->bitfield;
}

void g (struct s *a, struct s *b)
{
  a->bitfield = b->intfield;
}

void h (struct s *a, struct s *b)
{
  a->intfield = b->bitfield;
}
