



package a;

public abstract class CrossPackageImplA {
    public static void main(String[] args) {
        CrossPackageImplA a = new CrossPackageImplC();
        System.out.println(a.message());
    }

    abstract String message();
}

class CrossPackageImplC extends b.CrossPackageImplB {
    String message() { return "Hello, world"; }
}
