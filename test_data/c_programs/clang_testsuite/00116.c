typedef unsigned long long uint64_t;
int main(int argc, const char *argv[]) {
  for (uint64_t I = 0; I < 0xffffffff0; ++I) {
    if (I & 0xf) {
    } else {
    }
    switch ((I & 0xf) / 5) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    default:
      break;
    }
  }
  return 0;
}
