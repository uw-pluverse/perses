void sizeof_vla(int a) {
  if (a == 5) {
    char x[a];
    int y[sizeof(x)];
    y[4] = 4;
    y[5] = 5;
  }
}
void sizeof_vla_2(int a) {
  if (a == 5) {
    char x[a];
    int y[sizeof(x) / sizeof(char)];
    y[4] = 4;
    y[5] = 5;
  }
}
void sizeof_vla_3(int a) {
  if (a == 5) {
    char x[a];
    int y[sizeof(*&*&*&x)];
    y[4] = 4;
    y[5] = 5;
  }
}
