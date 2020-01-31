
import java.util.List;

class T7188968 {

    static class Foo<X> {
        Foo(List<X> ls, Object o) { }
        static <Z> Foo<Z> makeFoo(List<Z> lz, Object o) { return null; }
    }

    void test(List l) {
        new Foo(l, unknown);
        new Foo(l, unknown) { };
        new Foo<>(l, unknown);
        Foo.makeFoo(l, unknown);
    }
}
