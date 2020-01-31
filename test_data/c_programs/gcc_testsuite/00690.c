


volatile unsigned int w0, w1;
volatile int result;

void test_si() {

  result = !(w0 & w1);

  result = !(w0 & 0x00f0);

  result = !(w0 & (w1 << 4));
}

void test_si_tbnz() {

jumpto:
  if (w0 & 0x08) goto jumpto;
}

void test_si_tbz() {

jumpto:
  if (!(w1 & 0x08)) goto jumpto;
}

volatile unsigned long long x0, x1;

void test_di() {

  result = !(x0 & x1);

  result = !(x0 & 0x00f0);

  result = !(x0 & (x1 << 4));
}

void test_di_tbnz() {

jumpto:
  if (x0 & 0x08) goto jumpto;
}

void test_di_tbz() {

jumpto:
  if (!(x1 & 0x08)) goto jumpto;
}
