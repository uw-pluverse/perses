
class TestBridgeWithDefault {
    interface A { Object m(int x); }

    @Bridge("m(I)Ljava/lang/Object;")
    interface B extends A {
        String m(int x);
        default Integer m(long x) { return null; }
    }
}
