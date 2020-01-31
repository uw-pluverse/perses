



class LambdaConv13 {

    interface I {
        void m();
    }

    interface A extends I {}
    interface B extends I {}
    interface C extends A, B {}
    interface D extends A, I {}
    interface E extends B, I {}

    C c = ()-> { };
    D d = ()-> { };
    D e = ()-> { };
}
