struct s {
  int word;
  struct {
    int filler __attribute__ ((aligned (8)));
  };
};
void func (struct s *s)
{
  s->word = 0;
}
