


int f(unsigned a, unsigned b) {
  unsigned remove = a - b;
  return remove > a;
}

int g(unsigned a, unsigned b) {
  unsigned remove = a - b;
  return remove <= a;
}

int h(unsigned a, unsigned b) {
  unsigned remove = a - b;
  return a < remove;
}

int i(unsigned a, unsigned b) {
  unsigned remove = a - b;
  return a >= remove;
}
