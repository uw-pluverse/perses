



public class NameClashSameErasureNoOverride<X> {
    static class A {
        void m(NameClashSameErasureNoOverride<String> l) {}
    }

    static class B extends A {
        void m(NameClashSameErasureNoOverride<Integer> l) {}
    }
}
