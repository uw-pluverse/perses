

import java.util.List;

class TargetType06 {

    class Foo {
        Foo getFoo() { return null; }
    }

    interface Function<A,R> {
        R invoke(A a);
    }

    static <B> List<B> map(Function<B, B> function) { return null; }

    void test() {
        List<Foo> l = map(foo -> foo.getFoo());
    }
}
