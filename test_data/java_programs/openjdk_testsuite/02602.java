



package good.covar;

interface A {
    A f();
}
interface B {
    B f();
}
class C {
    public D f() { return null; }
}
class D extends C implements A, B {
    
    
}
