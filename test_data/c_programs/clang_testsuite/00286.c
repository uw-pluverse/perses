typedef float v4sf __attribute__((vector_size(16)));
typedef double v4df __attribute__((vector_size(32)));
struct ssf { v4sf v; };
struct sdf { v4df v; };
struct ssf2 { v4sf v[2]; };
struct sdf2 { v4df v[2]; };
v4sf foo1(struct ssf a, v4sf b, struct ssf2 c) {
  return a.v + b;
}
v4df foo2(struct sdf a, v4df b, struct sdf2 c) {
  return a.v + b;
}
