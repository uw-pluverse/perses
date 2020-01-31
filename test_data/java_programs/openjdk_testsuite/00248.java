

public class T6182630d {
    static class Foo<X> {
        public X x;
        public void m(X x) { }
    }
    interface Bar {}
    <T extends Foo, S extends Foo & Bar> void test1(T t, S s) {
        s.x = "BAD";
    }
}
