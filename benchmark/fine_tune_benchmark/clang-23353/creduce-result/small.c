int a, b;
char c;
char d(char e, char f) { return e * f; }
void g() {
  c = 6;
  for (; c != -7; c--)
    b ^= d(c, a) && 1;
}
int main() { return 0; }
