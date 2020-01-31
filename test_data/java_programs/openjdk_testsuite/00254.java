



public class T6182630 {
    static class Foo<X> {
        public X x;
        public void m(X x) { }
    }
    interface Bar {}
    <T extends Foo, S extends Foo & Bar> void test1(T t, S s) {
        t.x = "BAD";
        t.m("BAD");
        t.m(t.x);
        s.x = "BAD";
        s.m("BAD");
        s.m(s.x);
    }
}
