


int f(void) {
  return 42;
}

void assignf_(int(**ptr)(void)) {
  *ptr = f;
}
