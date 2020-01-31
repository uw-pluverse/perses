



public class NameClashSameErasureNoOverride1 {

    interface I<X> {
        void m(X l);
    }

    class A {
        void m(Object l) {}
    }

    class B extends A implements I<Integer> {
        public void m(Integer l) {}
    }
}
