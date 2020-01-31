

package p;

import static p.T6537020.C.s;

class T6537020 {

    static class A {
       static String s;
    }

    interface B {
       String s = "";
    }

    static class C extends A implements B { }

    Object o = s;
}
