

class T7022054neg2 {
    static class A {
        static A m(String s) { return null; }
    }
    static class B extends A {
        static <X extends String> A m(X s) { return null; }
    }
}
