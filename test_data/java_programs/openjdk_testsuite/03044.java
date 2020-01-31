



public class MethodReference15 {

    interface SAM {
        void m();
    }

    static void m() { }

    static void test() {
        SAM s = MethodReference15::m;
    }
}
