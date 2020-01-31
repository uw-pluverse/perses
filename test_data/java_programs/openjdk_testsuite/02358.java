



class OverrideCheck {
    static class A {
        public void f() {}
    }

    static class B extends A {
        @Override
        public void f() {}
    }
}
