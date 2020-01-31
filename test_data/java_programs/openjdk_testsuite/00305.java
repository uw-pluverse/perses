



class T7022054pos1 {
    static class A {
        A m(String s) { return null; }
    }
    static class B extends A {
        <X extends B> X m(String s) { return null; }
    }
}
