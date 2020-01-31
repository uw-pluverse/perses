



extern double fabs (double);

int a (int x) {
 return (x > 0 ? x : -x) >= 0;
}

int b (int x) {
 return (x > 0 ? x : -x) == 0;
}

int c (int x) {
 return (x > 0 ? x : -x) != 0;
}

int d (int x) {
 return 0 != (x > 0 ? x : -x);
}

int e (int x) {
 return 0 == (x > 0 ? x : -x);
}

int f (int x) {
 return 0 <= (x > 0 ? x : -x);
}

int g (int x) {
 return 0 > (x > 0 ? x : -x);
}

int h (float x) {
 return 0.0 > fabs(x);
}

int i (float x) {
 return fabs(x) == -0.0;
}
