



class InheritedPrivateImpl {

    interface I {
        public void foo();
    }

    static class C1 {
        private void foo() {}
    }

    static abstract class C2 extends C1 implements I {
    }
}
