


import java.util.List;

class T6369605b {
    static <T extends List<X>, X> List<T> m1() {
        return null;
    }

    static <T extends List<U>, U extends List<X>, X> List<T> m2() {
        return null;
    }

    static <T extends List<U>, U extends List<V>, V extends List<X>, X> List<T> m3() {
        return null;
    }

    List<?> l1 = m1();
    List<?> l2 = m2();
    List<?> l3 = m3();
}
