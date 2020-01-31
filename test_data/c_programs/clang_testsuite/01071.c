typedef float v4sf __attribute__ ((vector_size (16)));
struct s { v4sf v; };
v4sf foo (struct s a) {
  return a.v;
}
