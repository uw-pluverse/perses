



class LocalClassTest {
    void foo() {
        class Local_default_constructor {
            public void foo() {}
            public void foo(int m, int nm) {}
        }
        class Local_has_constructor {
            public Local_has_constructor() {}
            public Local_has_constructor(int a, int ba) {}
            public void foo() {}
            public void foo(int m, int nm) {}
        }
        new LocalClassTest().foo();
    }
}



