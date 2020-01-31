

class T6476118b {
    public final int compareTo(Object o) { return 0; }

    static class B extends T6476118b implements Comparable<B> {
        public int compareTo(B b){ return 0; }
    }
}
