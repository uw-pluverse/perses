double foo(int N, int *Array) {
  double v = 0.0;
#pragma clang loop vectorize(enable)
  for (int i = 0; i < N; i++) {
    switch(Array[i]) {
    case 0: v += 1.0f; break;
    case 1: v -= 0.5f; break;
    case 2: v *= 2.0f; break;
    default: v = 0.0f;
    }
  }
  return v;
}
