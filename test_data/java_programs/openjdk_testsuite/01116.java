



class ImproperTypeInnerRawParam {
    class Outer<S> {
        class Inner<T> {}
    }

    void m() {
        Object o = (Outer.Inner<?>)null;
    }
}
