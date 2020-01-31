



package importInherit;

import static importInherit.B.x;

class A {
    static int x = 12;
}

class B extends A {
}

class C {
    int y = x;
}
