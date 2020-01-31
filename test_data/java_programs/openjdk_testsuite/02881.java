



class LambdaExpr05 {

    interface SAM { int foo(int i); }

    SAM s1 = i -> i * 2;
    SAM s2 = i -> 2 * i;
}
