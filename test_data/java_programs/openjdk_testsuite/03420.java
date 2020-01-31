

class T7123100c {
    <E> E m(E e) {
        return null;
    }

    <Z> void test(Enum<?> e) {
        Z z = (Z)m(e);
    }
}
