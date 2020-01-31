


class TargetType42 {

    interface SAM<X, Y> {
        Y f(X x);
    }

    <Z> void m(SAM<String, SAM<Z, Object>> s, Z z) { }

    void test(Object obj) {
        m((x)->{
            class Foo { }
            return (x2)-> {
                new Foo();
                return null;
            };
        }, obj);
    }
}
