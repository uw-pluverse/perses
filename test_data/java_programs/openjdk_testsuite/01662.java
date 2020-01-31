

class Test extends Test {

    boolean cond;

    void m(Object o) {}

    { m(cond ? null : null); }
}
