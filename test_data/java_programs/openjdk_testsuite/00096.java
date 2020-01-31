



public abstract class T6278587 {
    interface A<T extends A<T>> {}
    interface B extends A<B> {}
    interface C extends B {}
    interface D<T> {}
    abstract <T extends A<T>, S extends T> D<T> m(S s);
    {
        C c = null;
        D<B> d = null;
        d = m(c);
        d = this.<B,C>m(c);
        this.<B,C>m(c);
    }
}
