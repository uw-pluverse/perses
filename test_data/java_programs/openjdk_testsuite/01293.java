




class DiamondAndAnonClass {
    static class Foo<X> {
        <Z> Foo() {}
    }
    void m() {
        Foo<String> foo = new <Integer> Foo<>();
    }
}
