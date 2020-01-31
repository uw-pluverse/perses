



class T6880344 {
    static class A<X1 extends G<X1>> {
        public A<N<X1>> xyz;
    }

    static class N<X2 extends G<X2>> implements G<N<X2>> { }

    interface G<X3 extends G<X3>> { }
}
