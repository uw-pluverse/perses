

import pack1.P1;

class A {
    private static class B {
        static class Inner {}
    }
}

class X extends pack1.P1 {
    X() { super("bar"); }
    void foo() {
        
        
        Object z = new R.S.T();         
    }
}

class Y {

    class Foo {
        class Bar {}
    }

    class C extends A.B {}              
    class D extends A.B.Inner {}        

    static class Quux {
        private static class Quem {
            P1.Foo.Bar x;               
            static class MyError extends Error {}
        }
    }
}

class Z {
    void foo() throws Y.Quux.Quem.MyError {
                                
        throw new Y.Quux.Quem.MyError();
                                
    }
}
