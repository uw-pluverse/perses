
class TestClassAndInterfaceBridgeIdentical02 {

    interface A<X extends Object> { void m(X x); }
    interface B<X extends Number> { void m(X x); }

    @Bridge("m(Ljava/lang/Object;)V")
    @Bridge("m(Ljava/lang/Number;)V")
    interface C extends A<Integer>, B<Integer> {
        void m(Integer i);
    }

    @Bridge("m(Ljava/lang/Object;)V")
    @Bridge("m(Ljava/lang/Number;)V")
    static abstract class D implements A<Integer>, B<Integer> {
        public abstract void m(Integer i);
    }

    @Bridge("m(Ljava/lang/Object;)V")
    @Bridge("m(Ljava/lang/Number;)V")
    static class E implements A<Integer>, B<Integer> {
        public void m(Integer i) { }
    }
}
