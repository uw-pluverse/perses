

public class T5009937<X> {
    static class A {
        static void m(T5009937<String> l) {}
    }

    static class B extends A {
        static void m(T5009937<Integer> l) {}
    }
}
