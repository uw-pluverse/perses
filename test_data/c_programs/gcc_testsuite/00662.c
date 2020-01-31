


volatile unsigned int w0, w1, w2, w3, w4;
volatile int result;

void test_si() {

  w0 = w1 + w2 + (w3 >= w4);
}

volatile unsigned long long int x0, x1, x2, x3, x4;

void test_di() {

  x0 = x1 + x2 + (x3 >= x4);
}
