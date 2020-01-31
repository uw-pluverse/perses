char ia[128];
char ib[128 +1];

int main() {
  int i;
  for(i = 0; i < 128; ++i) {
    ia[i] = ib[i + 1];
  }

  return 0;
}
