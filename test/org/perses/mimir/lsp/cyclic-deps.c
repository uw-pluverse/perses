#include <stdint.h>


int8_t d(int8_t d, int8_t b) {

  return

      d - b;
}

int32_t b(int32_t d, int32_t b) {

  return d && b > 0 && b > INT32_MAX - b

      ;
}

int32_t i;
int32_t h;
int32_t f[] = {1};
int32_t h;

int32_t c(int32_t *, int8_t, int32_t *);
uint16_t a() {

  int32_t b = 0;

  for (i = 4; i > -2; --i) {
    uint32_t h = 0;
    int32_t b = 0;

    for (h = -1; h; h = d(h, 1))

      c(0, b, &h);
  }

  return h;
}

int32_t c(int32_t *a, int8_t d, int32_t *f) {

  int32_t *c = &i;

  for (;;) {
    int32_t *a = &h;

    *a ^= b(1, *c);
    if (f[0])
      break;
  }
  return *c;
}
int main() {

  a();

  return 0;
}
