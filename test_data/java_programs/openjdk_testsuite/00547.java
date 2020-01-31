



class T4717181c {
    static abstract class A<T> {
        abstract void f(T t);
        abstract int f(Integer t);
    }
    static abstract class B extends A<Integer> {}
}
