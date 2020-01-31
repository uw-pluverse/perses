



extern unsigned char a [150];
extern unsigned char b [150];
extern unsigned char c [150];
extern unsigned char d [150];
extern unsigned char e [150];

void foo () {
  for (int i = 92; i <= 141; i += 2) {
    int tmp = (d [i] && b [i]) <= (a [i] > c [i]);
    e [i] = tmp >> b [i];
  }
}
