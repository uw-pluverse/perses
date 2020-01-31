



public class NameCollision2 {
    boolean x1 = false;
    boolean x2 = false;
    void foo() {
        class Local {{ x1 = true; }}
        { new Local(); }
        new Object() {
            class Local {{ x2 = true; }}
            { new Local(); }
        };
    }
    void check() {
        foo();
        if (!x1) throw new Error("x1");
        if (!x2) throw new Error("x2");
    }
    public static void main(String[] args) {
        new NameCollision2().check();
    }
}
