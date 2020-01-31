



interface I {
    void method();
}

interface J {
    int method();
}

public class InvalidIntfCast {
    public static void main(String[] args) {
        I i = null;
        J j = (J) i;
    }
}
