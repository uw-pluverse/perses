


class T8056984<T1 extends B&C, T2 extends T1> {
    public T8056984(T1 t1, T2 t2) {
        System.err.println(t1.hashCode());
        System.err.println(t2.hashCode());
    }
}
class B {
}
interface C {
    public int hashCode();
}
