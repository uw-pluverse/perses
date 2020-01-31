
class LambdaConv25 {

    interface A {
        <X> void m();
    }

    interface B {
        <X> void m();
    }

    interface C extends A, B { }

    void test() {
        C c = ()->{}; 
    }
}
