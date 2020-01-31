


class T7139681pos {
    int[] a;
    Iterable<Integer> b;

    void testArray() {
        for (int a : a) {
            int a2 = a;
        }
    }

    void testIterable() {
        for (Integer b : b) {
            Integer b2 = b;
        }
    }
}
