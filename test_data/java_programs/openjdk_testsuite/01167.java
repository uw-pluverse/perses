



public class NameClashSameErasureNoHide<X> {
    static class A {
        static void m(NameClashSameErasureNoHide<String> l) {}
    }

    static class B extends A {
        static void m(NameClashSameErasureNoHide<Integer> l) {}
    }
}
