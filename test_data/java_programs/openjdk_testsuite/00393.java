



class T6732484 {
    class A<T extends A<T>> {}
    class B extends A<B> {}

    A<? super B> f;
}
