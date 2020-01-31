typedef int type;
typedef type type;
typedef int type;
void f(int N) {
  typedef int type2;
  typedef type type2;
  typedef int type2;
  typedef int vla[N];
  typedef int vla[N];
  typedef int vla2[N];
  typedef vla2 vla3;
  typedef vla2 vla3;
}
