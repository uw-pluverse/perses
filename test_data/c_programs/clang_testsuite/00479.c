struct p {
  char a;
  int b;
} __attribute__ ((packed));
struct p t = { 1, 10 };
struct p u;
int main () {
  int tmp = t.b;
  u.b = tmp;
  return tmp;
}
