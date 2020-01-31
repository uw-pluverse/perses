



interface I {
    void throwCheckedException ();
}

class A {
    public void throwCheckedException () throws Throwable {
        throw new Throwable();
    }
}

class B extends A implements I {
}

public class UncaughtException {
    public static void main (String[] args) {
        I b = new B();
        b.throwCheckedException();
    }
}
