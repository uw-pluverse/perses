
class TargetType38 {

    interface I { }

    interface SAM {
        I m();
    }

    static Object m() { return null; }

    void test() {
        Object o1 = (SAM)()->new Object();
        Object o2 = (SAM)TargetType38::m;
    }
}
