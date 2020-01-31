


public class MethodReference61 {
    interface SAM {
        void m();
    }

    static class MyTester {
        public void ifoo() { }
    }

    public static void main(String args[]) {
        MyTester t = new MyTester() {
            SAM s = super::ifoo;
        };
    }
}
