



class DUSwitch {
    void foo() {
        final int i;
        assert true : i=3;
        i=4;
    }
    void bar(boolean b) {
        final int i;
        assert b : i=3;
        i=4;
    }
    void baz() {
        final int i;
        assert false : i=3;
        i=4;
    }
}
