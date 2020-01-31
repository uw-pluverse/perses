


class T8014643 {

    static class A {
        int b = 1;
    }

    static class B extends A {
        int b = 12;

        int m() { return (super.b); }
    }
}
