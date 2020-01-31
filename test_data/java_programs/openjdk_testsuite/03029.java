



import java.util.*;

class T8020804 {
    interface Supplier<D> {
        D make();
    }

    void m(Object o) { }
    void m(char[] c) { }

    <C extends Collection<?>> C g(Supplier<C> sc) { return null; }

    void test() {
        m(g(LinkedList<Double>::new));
    }
}
