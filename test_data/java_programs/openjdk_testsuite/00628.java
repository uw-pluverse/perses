



class E1 extends Exception {}
class E2 extends Exception {}
class E3 extends Exception {}
class E4 extends E1 {}
interface I1 {
    void foo() throws E1, E2;
}
interface I2 {
    void foo() throws E3, E4;
}
interface I3 extends I1, I2 {
    
}
class Blah {
    public void foo(I3 i3) {
        try {
            i3.foo();
        } catch (E4 e4) {
        }
    }
}
