enum e0 { E0 };
struct s0 {
  enum e0 a:31;
};
struct s0 t1_tmp;
int f0() {
  return __alignof__(t1_tmp);
}
