





interface Base {
    void m(Object... x);
}

interface VarargsClash extends Base {
    void m(Object[] x);
}
