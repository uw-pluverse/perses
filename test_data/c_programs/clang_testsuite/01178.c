enum {
  VALUE = 3
};
extern int glob_x;
int f(int x) {
  return x+glob_x+VALUE;
}
typedef struct {
  int x;
  int y;
} Vector;
int vector_get_x(Vector v) {
  int x = v.x;
  return x;
}
int f(int);
int f(int);
