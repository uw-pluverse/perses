struct s {
  unsigned long int field[0];
};
int foo[(((char *) &((struct s *) 0)->field[0]) - (char *) 0)];
