



class T6977800 {
    public static void test() {
        class A {
            int x = 1;
        }
        class B extends A {}
        System.out.println(new B().x);
    }

    static class A {}
}
