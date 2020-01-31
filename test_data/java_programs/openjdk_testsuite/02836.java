



public class Y<T> {
    private T t;
    class Foo extends Y<Y<T>> {
        Y<T> y = t;
    }
}
