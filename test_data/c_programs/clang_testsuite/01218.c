float g(void);
void func(void) {
  for (float x = 0.1f; x <= 1.0f; x += 0.1f) {}
  float f = 1.0f;
  for (; f > 0; --f) {}
  for (;;g()) {}
  for (int i = 0; i < 10; i += 1.0f) {}
  for (int i = 0; i < 10; ++i) {}
}
