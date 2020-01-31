


import java.util.*;

class TargetType50 {

    interface Factory<F> {
        F make();
    }

    static class Sink<T> {
        static <Z> Sink<Z> make() { return null; }
    }

    <Y, S extends Sink<Y>> List<Y> m(Factory<S> factory) { return null; }

    void test() {
        List<?> l1 = m(Sink::new);
        List<?> l2 = m(Sink::make);
        List<String> l3 = m(Sink::new);
        List<String> l4 = m(Sink::make);
    }
}
