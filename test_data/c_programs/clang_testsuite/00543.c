unsigned long li, lj, lk;
unsigned int ii, ij, ik;
extern void opaquelong(unsigned long);
extern void opaqueint(unsigned int);
void testlongadd() {
  li = lj + lk;
}
void testlongsub() {
  li = lj - lk;
}
void testlongmul() {
  li = lj * lk;
}
void testlongpostinc() {
  opaquelong(li++);
}
void testlongpreinc() {
  opaquelong(++li);
}
void testintadd() {
  ii = ij + ik;
}
void testintsub() {
  ii = ij - ik;
}
void testintmul() {
  ii = ij * ik;
}
void testintpostinc() {
  opaqueint(ii++);
}
void testintpreinc() {
  opaqueint(++ii);
}
