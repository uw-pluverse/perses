


extern void link_error (void);



struct s
{
  char d;
  int a, b;
  double m;
};

struct s foo (struct s r)
{
  struct s temp_struct1;
  struct s temp_struct2;
  struct s temp_struct3;
  temp_struct1 = r;
  temp_struct2 = temp_struct1;
  temp_struct3 = temp_struct2;
  return temp_struct3;
}
