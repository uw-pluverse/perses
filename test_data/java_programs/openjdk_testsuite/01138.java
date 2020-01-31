



interface A {
    int m();
}

interface B {
    String m();
}

interface TypesIncompatible extends A, B { }
