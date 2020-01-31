



class Box<T> {}

interface N1 {
    <T> Box<T> box(T t);
}
interface N2 {
    <T> Box<T> box(T t);
}

abstract class GenericMerge implements N1, N2 {
    void f(Object o) {
        box(o);
    }
}
