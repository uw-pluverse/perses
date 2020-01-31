





class Base {
    void m(Object... x) { }
}

class VarargsOverride extends Base {
    void m(Object[] x) { }
}
