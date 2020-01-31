
class TargetType52 {

    interface FI<T extends CharSequence, V extends java.util.AbstractList<T>> {
        T m(V p);
    }

    void m(FI<? extends CharSequence, ? extends java.util.ArrayList<? extends CharSequence>> fip) { }

    void test() {
        m(p -> p.get(0));
    }
}
