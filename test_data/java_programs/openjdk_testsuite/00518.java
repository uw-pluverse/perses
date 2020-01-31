




import java.io.*;

public class D extends C {
    public D() {
        super();
    }

    public D test() {
        System.out.println("D called");
        return new D();
    }

    public static void main(String[] agrs) {
        A obj = new D();
        obj.test();
    }
}
