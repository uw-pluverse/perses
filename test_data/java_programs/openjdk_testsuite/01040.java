

class Super {
    void m(Missing a) {}
    void m(String a) {}
}

abstract class AbstractSuper {
    abstract void m(Missing a);
    abstract void m(String a);
}

interface Missing {}
