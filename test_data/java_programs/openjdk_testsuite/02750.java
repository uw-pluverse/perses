



abstract class B {
    abstract void f();
    void access$1() {
        this.f();
    }
}

public class InternalHandshake extends B {
    void f() {
        System.out.println("correct");
    }
    public static void main(String[] args) {
        new InternalHandshake().access$1();
    }
}
