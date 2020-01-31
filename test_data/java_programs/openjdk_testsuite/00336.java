
class T7151802 {
    static class Foo<X> { }

    static class SubFoo<X> extends Foo<X> { }

    
    <Z extends Foo<String>> void get1(Z fz) { }
    void test1(Foo foo) { get1(foo); }

    
    <Z extends Foo<?>> void get2(Z fz) { }
    void test2(Foo foo) { get2(foo); }

    
    <Z> void get3(Foo<Z> fz) { }
    void test(Foo foo) { get3(foo); }

    
    <Z> void get4(Foo<?> fz) { }
    void test4(Foo foo) { get4(foo); }

    
    <Z extends Foo<String>> Z get5() { return null; }
    void test5() { SubFoo sf = get5(); }

    
    static <Z extends Foo<?>> Z get6() { return null; }
    void test6() { SubFoo sf = get6(); }

    
    void get7(Foo<String> fz) { }
    void test7(Foo foo) { get7(foo); }

    
    static void get8(Foo<?> fz) { }
    void test8(Foo foo) { get8(foo); }
}
