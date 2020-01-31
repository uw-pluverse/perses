



package importPrivate;

import static importPrivate.A.m;

class A {
    private static int m() {
        return 8;
    }
}

class MyTest {
    public static void main(String argv[]) {
        m();
    }
}
