typedef __attribute__((vector_size(16))) int int4;
int4 align1(int4 a, int4 b) { return (__builtin_ia32_palignr128((a), (b), (15))); }
int4 align2(int4 a, int4 b) { return (__builtin_ia32_palignr128((a), (b), (16))); }
int4 align3(int4 a, int4 b) { return (__builtin_ia32_palignr128((a), (b), (17))); }
int4 align4(int4 a, int4 b) { return (__builtin_ia32_palignr128((a), (b), (32))); }
typedef __attribute__((vector_size(8))) int int2;
int2 align5(int2 a, int2 b) { return (__builtin_ia32_palignr((a), (b), (8))); }
int2 align6(int2 a, int2 b) { return (__builtin_ia32_palignr((a), (b), (9))); }
int2 align7(int2 a, int2 b) { return (__builtin_ia32_palignr((a), (b), (16))); }
int2 align8(int2 a, int2 b) { return (__builtin_ia32_palignr((a), (b), (7))); }
