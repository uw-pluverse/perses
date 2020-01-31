

class T6665356 {
    class Outer<S> {
        class Inner<T> {}
    }

    void test1() {
        boolean b;
        b = null instanceof Outer.Inner;
        b = null instanceof Outer<?>.Inner;
        b = null instanceof Outer.Inner<?>;
        b = null instanceof Outer<?>.Inner<?>;
    }

    void test2() {
        boolean b;
        Object o;
        o = (Outer.Inner)null;
        o = (Outer<?>.Inner)null;
        o = (Outer.Inner<?>)null;
        o = (Outer<?>.Inner<?>)null;
    }
}
