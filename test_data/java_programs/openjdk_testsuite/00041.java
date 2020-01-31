



public class T6292765 {
    static class A<T> {}

    static class B<S> extends A< C<Object> > {}

    static class C<S> extends B<S> {}
}
