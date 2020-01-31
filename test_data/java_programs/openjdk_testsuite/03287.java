



import java.util.*;

class MethodReference10 {

    interface Getter<U, T> {
        public U get(T t);
    }

    public static <T, U extends Comparable<? super U>>
        void sortBy(Collection<T> s, Getter<U, T> getter) {};

    static class Foo {
        private String a;
        String getA(Foo f) { return f.a; }
    }

    public static void main(String[] args) {
        Collection<Foo> c = new ArrayList<Foo>();
        sortBy(c, new Foo()::getA);
    }
}
