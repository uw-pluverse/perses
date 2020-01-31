



class Casting5 {
    static interface Super<P> {}
    static class Y implements Super<Integer>{}
    static interface X extends Super<Double>{}
    static class S<L> extends Y {}
    static interface T<L> extends X {}

    public static void main(String... args) {
        S s = null; 
        T t = null; 
        t = (T) s;
    }
}
