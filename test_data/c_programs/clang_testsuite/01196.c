enum x;
extern struct y a;
extern union z b;
void foo() {
  (enum x)1;
  (struct y)a;
  (union z)b;
  (union z)1;
}
