



package p;

import static p.A.*;
import static p.B.*;

interface A {
    int K = 3;
}
interface B {
    int K = 4;
}

class C {
    void f() {
        int x = K; 
    }
}
