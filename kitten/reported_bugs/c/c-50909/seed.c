

typedef short a;

typedef struct {
  a b, c, d, e;
} f;

f *g;

long h;

void
i() {
  f j;
  for (; h; h++)
    *g++ = j;
}
