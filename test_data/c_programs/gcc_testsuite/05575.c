


extern void abort ();
extern void exit (int);

int f (int a) {
 if (a != (-2147483647 -1)) {
  a = a > 0 ? a : -a;
  if (a < 0)
    return 1;
 }
 return 0;
}

int g (int b) {
 if (b != (-2147483647 -1)) {
  b = b > 0 ? b : -b;
  if (b >= 0)
    return 0;
 }
 return 1;
}
