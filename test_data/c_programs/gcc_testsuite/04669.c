




int g(void) __attribute__((noreturn));
int g2(void) __attribute__((noreturn));
void h(void) __attribute__((noreturn));


int g(void) {
  return 1;
}

int g2(void) {
  h();
}

typedef int ft(void);
volatile ft vg;
volatile ft vg2;

int vg(void);
int vg2(void);

int vg(void) {
  return 1;
}

int vg2(void) {
  h();
}
