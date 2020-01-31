

class TargetType27 {
    interface F<X, Y>  {
        Y f(X a);
    }

    <A, R> F<A, R> m(F<A, R>  f) { return null; }

    void test() {
        m((String s1) ->  (String s2) ->  new Integer(1));
    }
}
