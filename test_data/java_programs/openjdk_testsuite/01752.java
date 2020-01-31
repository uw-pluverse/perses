



interface Pos12 {

    default Object m() {
        Object o = this;
        f(this);
        return this;
    }

    void f(Object o);
}
