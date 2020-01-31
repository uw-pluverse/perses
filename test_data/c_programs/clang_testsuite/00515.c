static _Bool f0_0(void *a0) { return (_Bool) a0; }
int f0() { return f0_0((void*) 0x2); }
_Bool f1(void) {
  return (_Bool) ({ void (*x)(); x = 0; });
}
