



class T7022054pos2 {
    static class A {
        static A m(String s) { return null; }
    }
    static class B extends A {
        static <X extends B> X m(String s) { return null; }
    }
}
