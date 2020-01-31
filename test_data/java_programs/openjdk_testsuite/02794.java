



interface I {
    void method();
}

class A {
    public void method() throws Exception {
    }
}

public
class ThrowsConflict extends A implements I {
}
