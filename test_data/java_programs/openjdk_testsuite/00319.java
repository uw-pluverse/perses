

class T6476118a {
    static class A {
        public int compareTo(Object o) { return 0; }
    }

    static class B extends A implements Comparable<B>{
        public int compareTo(B b){ return 0; }
    }
}
