


import java.util.List;

class TargetType73 {

    interface Function<X,Y> {
        Y m(X x);
    }

    static void test() {
        m(TargetType73::g);
    }

    public static <T> List<T> g(T... a) {
        return null;
    }

    public static <C> void m(Function<String, C> zipper) {  }
}
