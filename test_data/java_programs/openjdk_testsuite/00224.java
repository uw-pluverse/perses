

class Neg11 {

    void test() {
        class Foo<X extends Number> { }
        Foo<?> f1 = new UndeclaredName<>(); 
        Foo<?> f2 = new UndeclaredName<>() {}; 
    }
}
