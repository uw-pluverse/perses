


class TargetType56 {
    <Z> Z m(Z z) { return null; }

    void test() {
        double d1 = m(1);
        double d2 = m((Integer)null);
        double d3 = m(m(1));
        double d4 = m(m((Integer)null));
    }
}
