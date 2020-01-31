



package Casting3;

class A<T extends A<T>> {
    <U extends A<U>> void f() {
        A<U> a = (A<U>) this;
    }
}
