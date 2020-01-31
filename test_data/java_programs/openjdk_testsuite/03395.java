



public class T6302214 {
    class B extends A<Object> {
        void m2() {
            m3((X2) m());
        }
        void m3(X2 i) { }
    }

    public class A<T> {
        X<? extends T> m() {
            return null;
        }
    }

    class X2 extends X<String> { }

    class X<T> { }
}
