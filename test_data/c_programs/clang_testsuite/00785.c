struct s1 {
  int x;
} __attribute__((aligned(8)));
struct s1 x1;
void f1_helper(struct s1);
void f1() {
  f1_helper(x1);
}
