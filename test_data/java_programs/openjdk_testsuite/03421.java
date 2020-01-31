

class T7123100d {
    <E extends Enum<E>> E m(Enum<E> e) {
        return null;
    }

    <Z> void test(Enum<?> e) {
        Z z = (Z)m(e);
    }
}
