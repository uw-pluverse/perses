

class T8016177c {

    interface Function<X, Y> {
        Y m(X x);
    }

    interface ExtFunction<X, Y> extends Function<X, Y> { }

    <U, V> U m1(Function<U, V> f) { return null; }
    <U, V> U m1(ExtFunction<U, V> f) { return null; }

    void m2(Function<Integer, Integer> f) { }
    void m2(ExtFunction<Integer, Integer> f) { }

    void m3(Function<Integer, Integer> f) { }
    void m3(ExtFunction<Object, Integer> f) { }

    int g1(Object s) { return 1; }

    int g2(Number s) { return 1; }
    int g2(Object s) { return 1; }

    void test() {
        m1((Integer x)->x); 
        m2((Integer x)->x); 
        m3((Integer x)->x); 

        m1(x->1); 
        m2(x->1); 
        m3(x->1); 

        m1(this::g1); 
        m2(this::g1); 
        m3(this::g1); 

        m1(this::g2); 
        m2(this::g2); 
        m3(this::g2); 
    }
}
