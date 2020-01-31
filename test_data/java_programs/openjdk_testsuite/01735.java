



class Pos14 {
    interface A { default Object m() { return null; } }
    static abstract class B { abstract public String m(); }

    static abstract class C extends B implements A {
        void test() {
            m().length();
        }
    }
}
