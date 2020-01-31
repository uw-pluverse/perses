



public class MethodRef8 {
    void test(Box<? extends Box<? extends Number>> b) {
        Number n1 = b.map(Box::get).get();
        Number n2 = b.<Number>map(Box::get).get();
    }

    interface Func<S,T> { T apply(S arg); }

    interface Box<T> {
        T get();
        <R> Box<R> map(Func<T,R> f);
    }
}
