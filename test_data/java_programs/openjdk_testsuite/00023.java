



public class T6294779a {

    interface A {
        A m();
    }

    interface B extends A {
        B m();
    }

    interface C extends A {
        C m();
    }

    interface D extends B, C {
        D m();
    }
}
