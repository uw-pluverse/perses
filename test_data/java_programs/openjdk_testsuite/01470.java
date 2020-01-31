



abstract class Base {
    abstract void m();
}

class AbstractCantBeAccessed extends Base {
    void m() {
        super.m();
    }
}
