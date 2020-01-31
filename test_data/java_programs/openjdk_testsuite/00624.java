



interface A {
    B f();
}
interface B {
    C f();
}
interface C extends A,B {
}
