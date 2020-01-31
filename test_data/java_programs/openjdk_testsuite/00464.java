
class T8016640 {
    static class Foo<X,Y> { }
    static class BadFoo<T> extends Foo<T> { }
    static class SubBadFoo<T> extends BadFoo<T> { }
}
