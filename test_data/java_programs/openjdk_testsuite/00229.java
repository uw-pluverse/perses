

class Neg01<X extends Number> {

    Neg01(X x) {}

    <Z> Neg01(X x, Z z) {}

    void test() {
        Neg01<String> n1 = new Neg01<>("");
        Neg01<? extends String> n2 = new Neg01<>("");
        Neg01<?> n3 = new Neg01<>("");
        Neg01<? super String> n4 = new Neg01<>("");

        Neg01<String> n5 = new Neg01<>("", "");
        Neg01<? extends String> n6 = new Neg01<>("", "");
        Neg01<?> n7 = new Neg01<>("", "");
        Foo<? super String> n8 = new Neg01<>("", "");
    }
}
