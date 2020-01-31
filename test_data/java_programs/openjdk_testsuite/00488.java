



class T6729401 {

    interface I<U,W> {
        <T extends I<U,T>> void m(I<U,T> x);
    }

    <X extends I<Object,X>,Y extends I<Object,Y>> void test(I<Object,X> x, I<Object,Y> y) {
        x.<Y>m(y);
        x.m(y);
        y.<X>m(x);
        y.m(x);
    }
}
