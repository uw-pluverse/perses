int temp;
#pragma omp declare reduction
#pragma omp declare reduction {
#pragma omp declare reduction(
#pragma omp declare reduction(#
#pragma omp declare reduction(/
#pragma omp declare reduction(+
#pragma omp declare reduction(for
#pragma omp declare reduction(if:
#pragma omp declare reduction(oper:
#pragma omp declare reduction(oper;
#pragma omp declare reduction(fun : int
#pragma omp declare reduction(+ : const int:
#pragma omp declare reduction(- : volatile int:
#pragma omp declare reduction(* : int;
#pragma omp declare reduction(& : double char:
#pragma omp declare reduction(^ : double, char, :
#pragma omp declare reduction(&& : int, S:
#pragma omp declare reduction(|| : int, double : temp += omp_in)
#pragma omp declare reduction(| : char, float : omp_out += temp)
#pragma omp declare reduction(fun : long : omp_out += omp_in) {
#pragma omp declare reduction(fun : unsigned : omp_out += temp))
#pragma omp declare reduction(fun : long(void) : omp_out += omp_in)
#pragma omp declare reduction(fun : long[3] : omp_out += omp_in)
#pragma omp declare reduction(fun23 : long, int, long : omp_out += omp_in)
#pragma omp declare reduction(fun222 : long : omp_out += omp_in)
#pragma omp declare reduction(fun1 : long : omp_out += omp_in) initializer
#pragma omp declare reduction(fun2 : long : omp_out += omp_in) initializer {
#pragma omp declare reduction(fun3 : long : omp_out += omp_in) initializer[
#pragma omp declare reduction(fun4 : long : omp_out += omp_in) initializer()
#pragma omp declare reduction(fun5 : long : omp_out += omp_in) initializer(temp)
#pragma omp declare reduction(fun6 : long : omp_out += omp_in) initializer(omp_orig
#pragma omp declare reduction(fun7 : long : omp_out += omp_in) initializer(omp_priv 12)
#pragma omp declare reduction(fun8 : long : omp_out += omp_in) initializer(omp_priv = 23)
#pragma omp declare reduction(fun8 : long : omp_out += omp_in) initializer(omp_priv = 23))
#pragma omp declare reduction(fun9 : long : omp_out += omp_in) initializer(omp_priv = )
int fun(int arg) {
#pragma omp declare reduction(red : int : omp_out++)
  {
#pragma omp declare reduction(red : int : omp_out++)
#pragma omp declare reduction(red : int : omp_out++)
    {
#pragma omp declare reduction(red : int : omp_out++)
    }
  }
  return arg;
}
