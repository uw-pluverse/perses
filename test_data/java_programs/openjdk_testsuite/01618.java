



public class InitializeTarget {
    public static void main(String[] args) {
        A.class.toString();
    }
}

class A {
    static {
        if (true) throw new Error();
    }
}
