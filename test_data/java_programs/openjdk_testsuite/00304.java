

class T7022054neg1 {
    static class A {
        A m(String s) { return null; }
    }
    static class B extends A {
        <X extends String> A m(X s) { return null; }
    }
}
