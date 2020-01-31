typedef int v4si __attribute__ ((vector_size (16)));






v4si arg1 (v4si p, v4si q) { return p & q; }
v4si arg2 (v4si p, v4si q) { return p | q; }
v4si arg3 (v4si p, v4si q) { return p ^ q; }
v4si arg4 (v4si p) { return ~ p; }
v4si arg5 (v4si p, v4si q) { return ~(p & q); }
v4si arg6 (v4si p, v4si q) { return ~(p | q); }
v4si arg7 (v4si p, v4si q) { return ~(p ^ q); }
v4si arg8 (v4si p, v4si q) { return (~p) & q; }
v4si arg9 (v4si p, v4si q) { return (~p) | q; }
v4si arg10(v4si p, v4si q) { return (~p) ^ q; }
v4si arg11(v4si p, v4si q) { return p & (~q); }
v4si arg12(v4si p, v4si q) { return p | (~q); }
v4si arg13(v4si p, v4si q) { return p ^ (~q); }

void ptr1 (v4si *p) { p[0] = p[1] & p[2]; }
void ptr2 (v4si *p) { p[0] = p[1] | p[2]; }
void ptr3 (v4si *p) { p[0] = p[1] ^ p[2]; }
void ptr4 (v4si *p) { p[0] = ~p[1]; }
void ptr5 (v4si *p) { p[0] = ~(p[1] & p[2]); }
void ptr6 (v4si *p) { p[0] = ~(p[1] | p[2]); }
void ptr7 (v4si *p) { p[0] = ~(p[1] ^ p[2]); }
void ptr8 (v4si *p) { p[0] = ~(p[1]) & p[2]; }
void ptr9 (v4si *p) { p[0] = (~p[1]) | p[2]; }
void ptr10(v4si *p) { p[0] = (~p[1]) ^ p[2]; }
void ptr11(v4si *p) { p[0] = p[1] & (~p[2]); }
void ptr12(v4si *p) { p[0] = p[1] | (~p[2]); }
void ptr13(v4si *p) { p[0] = p[1] ^ (~p[2]); }

