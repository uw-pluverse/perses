


void *a;
void *b(void);
void *e(void);

void *
c() {
  void *d;
  if (d == b && e())
    d = a;
  return d;
}
