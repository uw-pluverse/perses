



public class TargetType32 {

    interface A<X> {
        X m();
    }

    interface B<X> extends A<X> {}

    void m(A<Integer> a) { }
    void m(B<String> b) { }

    <Z extends Integer> void m2(A<Z> a) { }
    <Z extends String> void m2(B<Z> b) { }

    void m3(A<TargetType32> a) { }
    void m3(B<String> b) { }

    <Z> void m4(A<Z> a) { }
    <Z extends String> void m4(B<Z> b) { }

    int intRes() { return 42; }

    void testLambda(boolean flag) {
        A<Integer> c = flag ? (() -> 23) : (() -> 42);
        m(flag ? (() -> 23) : (() -> 42));
        m2(flag ? (() -> 23) : (() -> 23));
    }

    void testMethodRef(boolean flag) {
        A<Integer> c = flag ? this::intRes : this::intRes;
        m(flag ? this::intRes : this::intRes);
        m2(flag ? this::intRes : this::intRes);
    }

    void testConstrRef(boolean flag) {
        A<TargetType32> c = flag ? TargetType32::new : TargetType32::new;
        m3(flag ? TargetType32::new : TargetType32::new);
        m4(flag ? TargetType32::new : TargetType32::new);
    }

    public static void main(String[] args) {
        TargetType32 test = new TargetType32();
        test.testLambda(true);
        test.testMethodRef(true);
        test.testConstrRef(true);
    }
}
