



public class Foo<T> {
    private T t;
    private Foo<?>.Inner[] inner;
    public Foo(T t) {
        this.t = t;
        inner = new Foo<?>.Inner[10];
    }
    private class Inner {}
}
