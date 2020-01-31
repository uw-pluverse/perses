


struct s {
  char *p;
};

void
func(struct s *ptr)
{
  *(void **)&ptr->p = 0;
}
