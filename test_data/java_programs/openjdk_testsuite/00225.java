

class Neg09 {
    class Member<X> {}

    static class Nested<X> {}

    void testSimple() {
        Member<?> m1 = new Member<>() {};
        Nested<?> m2 = new Nested<>() {};
    }

    void testQualified() {
        Member<?> m1 = this.new Member<>() {};
        Nested<?> m2 = new Neg09.Nested<>() {};
    }
}
