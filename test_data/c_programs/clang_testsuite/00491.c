#pragma omp declare reduction(+ : int, char : omp_out *= omp_in)
#pragma omp declare reduction(fun : float : omp_out += omp_in) initializer(omp_priv = omp_orig + 15)
struct SSS {
  int field;
#pragma omp declare reduction(+ : int, char : omp_out *= omp_in)
};
void init(struct SSS *priv, struct SSS orig);
#pragma omp declare reduction(fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
int main() {
#pragma omp declare reduction(fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
  {
#pragma omp declare reduction(fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
  }
  return 0;
}
