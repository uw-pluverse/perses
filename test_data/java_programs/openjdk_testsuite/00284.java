
class TestClassAndInterfaceBridgeIdentical01 {

    interface A { Object m(); }
    interface B { Number m(); }

    @Bridge("m()Ljava/lang/Object;")
    @Bridge("m()Ljava/lang/Number;")
    interface C extends A, B {
        Integer m();
    }

    @Bridge("m()Ljava/lang/Object;")
    @Bridge("m()Ljava/lang/Number;")
    static abstract class D implements A, B {
        public abstract Integer m();
    }

    @Bridge("m()Ljava/lang/Object;")
    @Bridge("m()Ljava/lang/Number;")
    static class E implements A, B {
        public Integer m() { return 1; }
    }
}
