



class Pos15 {
    interface A { default String m() { return null; } }
    static abstract class B { abstract public Object m(); }

    static abstract class C extends B implements A {
        void test() {
            m().length();
        }
    }
}
