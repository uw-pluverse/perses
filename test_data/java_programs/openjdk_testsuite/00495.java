

class T6910550c {
    void m(Object[] x) {}
    void m(Object... x) {}

    { m(); }
    { m(null); }
    { m(null, null); }
    { m(null, null, null); }
}
