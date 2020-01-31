

public class PrimitiveTypeBoxingTest {

    static void foo(long arg) {}
    static void bar(int arg) {}

    interface F<X> { void get(X arg); }

    <Z> void m1(F<Z> f, Z arg) {}
    <Z> void m2(Z arg, F<Z> f) {}

    void test() {
        m1(PrimitiveTypeBoxingTest::foo, 23); 
        m2(23, PrimitiveTypeBoxingTest::foo); 

        m1(PrimitiveTypeBoxingTest::bar, 23); 
        m2(23, PrimitiveTypeBoxingTest::bar); 
    }
}
