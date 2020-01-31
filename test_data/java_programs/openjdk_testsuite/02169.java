


class T6747671<E> {

    static class B<X> {}

    class A<X> {
        class X {}
        class Z<Y> {}
    }


    A.X x1;
    A.Z z1;

    T6747671.B<Integer> b1;
    T6747671.B b2;

    A<String>.X x2;
    A<String>.Z<Integer> z2;
    A<B>.Z<A<B>> z3;

    void test(Object arg1, B arg2) {
        boolean b = arg1 instanceof A;
        Object a = (A)arg1;
        A a2 = new A() {};
        a2.new Z() {};
    }

    @TA B @TA[] arr = new @TA B @TA [0];
    Class<B[]> classes1;
    Class<B>[] classes2;

    @java.lang.annotation.Target(java.lang.annotation.ElementType.TYPE_USE)
    @interface TA { }
}
