int a, b;
int *c1 = 1 < 2 ? &a : &b;
int *c2 = 3 != 3LL ? &b : &a;
int *c3 = !(3 <= 4.0) ? &b : &a;
int *c4 = &a - (6 * 5 > 30);
int *c5 = &a + (6 * 5 >= 30);
int c6 = 44 < 33;
