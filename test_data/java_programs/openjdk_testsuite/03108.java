


class TargetType70  {

    static class Sup {}
    static class Sub extends Sup {}

    interface I<T extends GenSup<U>, U> {
        T m(U o);
    }

    static class GenSup<T> {
        GenSup(T f) { }
    }

    static class GenSub<T> extends GenSup<T> {
        GenSub(T f) { super(f); }
    }

    <T extends Sup> void m(I<? extends GenSup<T>, T> o1, T o2) { }

    void test(Sub sub) {
        m(GenSub::new, sub);
    }
}
