

@ExpectedElementCounts(constructors=2, fields=5, methods=4, types=3)
public class Foo1 {
    private Foo1() {}
    private Foo1(Object o) {}

    private static class Type1 {}
    private static class Type2 {}
    private static class Type3 {}

    static void method1(){};
    void method2(){};
    static void method3(){};
    void method4(){};

    static Object field1;
    int field2;
    int field3 = 3;
    Object field4;
    static double field5 = 3.14159;
}
