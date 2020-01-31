


import java.util.List;

class T6369605a {
    static <T extends List<T>> T m1() {
        return null;
    }

    static <T extends List<U>, U extends List<T>> T m2() {
        return null;
    }

    static <T extends List<U>, U extends List<V>, V extends List<T>> T m3() {
        return null;
    }

    List<?> l1 = m1();
    List<?> l2 = m2();
    List<?> l3 = m3();
}

