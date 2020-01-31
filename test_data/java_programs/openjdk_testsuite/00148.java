



public class T5080917 {
    static interface I { }
    static class X { }
    static class A extends X implements I { }
    static class B extends X implements I { }
    void test(A a, B b) {
        X x = (a.hashCode() == b.hashCode()) ? a : b;
    }
}
