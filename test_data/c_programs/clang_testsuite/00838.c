typedef __attribute__((vector_size(16))) char v16i8;
v16i8 f0(v16i8 a, v16i8 b) {
  __builtin_tbegin ((void *)0);
  v16i8 tmp = __builtin_s390_vaq(a, b);
  return tmp;
}
