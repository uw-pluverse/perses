



public class T6869075 {

    static class Foo<X> {
        X x;
        Foo (X x) {
            this.x = x;
        }
    }

    static void test1(Foo<String> foo) {
        String start = foo.x;
        equals(foo.x += "foo", start + "foo");
    }

    static void test2(Foo<String> foo) {
        String start = foo.x;
        equals((foo.x += "foo"), (start + "foo"));
    }

    static void test3(Foo<String> foo) {
        String start = foo.x;
        equals(((foo.x += "foo")), ((start + "foo")));
    }

    public static void main(String[] args) {
        test1(new Foo<String>("Hello!"));
        test2(new Foo<String>("Hello!"));
        test3(new Foo<String>("Hello!"));
    }

    static void equals(String found, String req) {
        if (!found.equals(req)) {
            throw new AssertionError("Error (expected: "+ req +
                                     " - found: " + found + ")");
        }
    }
}
