



class DisjunctiveTypeTest {

    static class A extends IllegalArgumentException {
       A(String a) { super(a); }
    }

    class B extends IllegalArgumentException {
       B(String b) { super(b); }
    }

    void m() throws A,B {}

    void test() {
        try {
            m();
        } catch (A|B e) {
            throw new IllegalArgumentException(e);
        }
    }
}
