



class AbstractCantBeInstantiated {
    abstract class C { }

    void m() {
        new C();
    }
}
