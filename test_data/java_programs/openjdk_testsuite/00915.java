



class T4743490 {
    static class A {
        public void m(Object o, String s) {}
    }
    interface B {
        void m(String s, Object o);
    }
    static abstract class C extends A implements B {
    }
    static abstract class D extends C {
        void foo() {
            C c = null;
            super.m("", ""); 
        }
    }
}
