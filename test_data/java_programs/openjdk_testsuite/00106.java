

import java.util.List;



class T6938454b {

    static interface A {}
    static interface B extends A {}
    static class C implements B {}

    <T, R extends T, S extends R> List<R> m(List<T> l, S s) {
        return null;
    }

    List<B> test(List<A> la) {
        return m(la, new C());
    }
}
