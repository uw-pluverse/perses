typedef int __attribute__((mode(byte))) __attribute__((vector_size(4))) vec_t1;
typedef int __attribute__((mode(QI))) __attribute__((vector_size(8))) vec_t2;
typedef int __attribute__((mode(SI))) __attribute__((vector_size(16))) vec_t3;
typedef int __attribute__((mode(DI))) __attribute__((vector_size(64)))vec_t4;
typedef float __attribute__((mode(SF))) __attribute__((vector_size(128))) vec_t5;
typedef float __attribute__((mode(DF))) __attribute__((vector_size(256))) vec_t6;
void check() {
  vec_t1 v1;
  vec_t2 v2;
  vec_t3 v3;
  vec_t4 v4;
  vec_t5 v5;
  vec_t6 v6;
}
int check_size1() { return sizeof(vec_t1); }
int check_size2() { return sizeof(vec_t2); }
int check_size3() { return sizeof(vec_t3); }
int check_size4() { return sizeof(vec_t4); }
int check_size5() { return sizeof(vec_t5); }
int check_size6() { return sizeof(vec_t6); }
