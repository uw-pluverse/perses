



class Pos02 {
    interface IA { default int m() { return Pos02.m1(this); } }
    interface IB { default int m() { return Pos02.m2(this); } }

    static class A implements IA {}
    static class B implements IB {}

    static class AB implements IA, IB {
        public int m() { return 0; }
        void test() {
            AB.this.m();
            IA.super.m();
        }
    }

    static int m1(IA a) { return 0; }
    static int m2(IB b) { return 0; }
}
