typedef float v4f32 __attribute__ ((__vector_size__ (16)));

void foo (float);
extern v4f32 x, y;

int main() {
  v4f32 z = x + y;
  foo (z[2]);
}
