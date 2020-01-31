



class C {
    class D {}
    interface E {}
}

interface I {
    class J {}
    interface K{}
}

class L extends C {}

interface M extends I {}

class X extends C implements I {
    D d;
    E e;
    J j;
    K k;
}

class Y extends L implements M {
    D d;
    E e;
    J j;
    K k;
}

class Outer {

    class C {
        class D {}
        
    }

    interface I {
        class J {}
        interface K{}
    }

    class L extends C {}

    interface M extends I {}

    class X extends C implements I {
        D d;
        J j;
        K k;
    }

    class Y extends L implements M {
        D d;
        J j;
        K k;
    }

    void test() {

        

        class C {
            class D {}
            
        }

        class L extends C {}

        class X extends C {
            D d;
        }

        class Y extends L {
            D d;
        }

    }

}
