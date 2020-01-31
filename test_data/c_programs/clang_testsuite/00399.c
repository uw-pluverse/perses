float fabsf(float a) {
  float res;
  __asm __volatile__("fabss  %1, %0;"
                     : "=e"(res)
                     : "f"(a));
  return res;
}
