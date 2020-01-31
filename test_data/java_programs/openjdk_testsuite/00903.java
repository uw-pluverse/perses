



import java.lang.reflect.Modifier;

public enum AbstractEnum1 implements AE1_I {
    toto {
        public void m() {
        }
    }
    ;
    public static void main(String[] args) {
        if (!Modifier.isAbstract(AbstractEnum1.class.getModifiers()))
            throw new Error();
    }
}

interface AE1_I {
    void m();
}
