


#pragma omp declare reduction (| : long int : omp_out |= omp_in)
#pragma omp declare reduction (+ : char : omp_out += omp_in)
typedef short T;
#pragma omp declare reduction (min : T : omp_out += omp_in)
#pragma omp declare reduction (* : _Complex double : omp_out *= omp_in)

void
foo (void)
{
#pragma omp declare reduction (| : long int : omp_out |= omp_in)
#pragma omp declare reduction (+ : char : omp_out += omp_in)
#pragma omp declare reduction (min : T : omp_out += omp_in)
#pragma omp declare reduction (* : _Complex double : omp_out *= omp_in)
}

#pragma omp declare reduction (| : __typeof (foo) : omp_out |= omp_in)
#pragma omp declare reduction (+ : char () : omp_out += omp_in)
#pragma omp declare reduction (min : T[2] : omp_out += omp_in)

void
bar (void)
{
#pragma omp declare reduction (| : __typeof (foo) : omp_out |= omp_in)
#pragma omp declare reduction (+ : char () : omp_out += omp_in)
#pragma omp declare reduction (min : T[2] : omp_out += omp_in)
}

struct A { int a; };
#pragma omp declare reduction (| : const struct A : omp_out.a |= omp_in.a)
#pragma omp declare reduction (+ : __const struct A : omp_out.a += omp_in.a)
typedef volatile struct A T2;
#pragma omp declare reduction (min : T2 : omp_out.a += omp_in.a)
#pragma omp declare reduction (* : struct A *__restrict : omp_out->a *= omp_in->a)

void
baz (void)
{
#pragma omp declare reduction (| : const struct A : omp_out.a |= omp_in.a)
#pragma omp declare reduction (+ : __const struct A : omp_out.a += omp_in.a)
 typedef volatile struct A T3;
#pragma omp declare reduction (min : T3 : omp_out.a += omp_in.a)
#pragma omp declare reduction (* : struct A *__restrict : omp_out->a *= omp_in->a)
}
