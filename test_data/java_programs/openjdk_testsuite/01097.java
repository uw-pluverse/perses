

package T4524388;

interface Interface {
    void method();
}

class Testa implements Interface {
    void method() {}
}

class A {
    void method() {}
}

class B extends A implements Interface {
}
