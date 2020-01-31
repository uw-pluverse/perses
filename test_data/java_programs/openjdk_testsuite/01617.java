



public class InitializeOuter {
    public static void main(String[] args) {
        new A.B();
    }
}

class A {
    static {
        if (true) throw new Error();
    }
    public static class B {
        B() {
            Object o = InitializeOuter.class;
        }
    };
}
