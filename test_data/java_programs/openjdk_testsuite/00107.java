



class T6938454a {

    static abstract class A { }

    static class B extends A { }

    B getB(B b) {
        return makeA(b);
    }

    <X extends A, Y extends X> Y makeA(X x) {
        return (Y)new B();
    }
}
