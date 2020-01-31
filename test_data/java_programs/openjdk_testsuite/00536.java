

class T7034511a {

    interface A<T> {
        void foo(T x);
    }

    interface B<T> extends A<T[]> { }

    static abstract class C implements B<Integer> {
        <T extends B<?>> void test(T x, String[] ss) {
            x.foo(ss);
        }
    }
}
