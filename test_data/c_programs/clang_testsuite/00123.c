int never_called(int i) {
  if (i) {}
  for (i = 0; i < 100; ++i) {
  }
  while (--i) {}
  do {} while (i++ < 75);
  switch (i) {
  case 12: return 3;
  case 82: return 0;
  default: return 89;
  }
}
int dead_code(int i) {
  if (i) {
    if (!i) {}
    for (i = 0; i < 100; ++i) {
    }
    while (--i) {}
    do {} while (i++ < 75);
    switch (i) {
    case 12: return 3;
    case 82: return 0;
    default: return 89;
    }
  }
  return 2;
}
int main(int argc, const char *argv[]) {
  dead_code(0);
  return 0;
}
