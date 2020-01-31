



package ambig1;

import static ambig1.A.f;
import static ambig1.B.f;

class A {
    static void f(int i) {}
}
class B {
    static void f(int i) {}
}

class Main {
    void g() {
        f(2);
    }
}
