



public abstract class T6278587Neg {
    interface A<T extends A<T>> {}
    interface B extends A<B> {}
    interface C extends B {}
    interface D<T> {}
    abstract <T extends A<T>, S extends T> D<T> m(S s);
    {
        C c = null;
        m(c);
    }
}
