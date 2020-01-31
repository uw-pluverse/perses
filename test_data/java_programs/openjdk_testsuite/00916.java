



class A {
    private void m(int a, int b) { }
}

class T6776289 {
    static void m(int a, String s) { }
    class B extends A {
        public void test() {
            m(1, "");
        }
    }
}
