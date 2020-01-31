extern int NestedVar1;
enum {
  VALUE = 3
};
extern int TopVar;
typedef struct {
  int x;
  int y;
  int z;
  int w;
} Vector;
static inline int vector_get_x(Vector v) {
  int x = v.x;
  return x;
}
extern int PreambleVar;
extern int LocalVar;
int LocalVar;
