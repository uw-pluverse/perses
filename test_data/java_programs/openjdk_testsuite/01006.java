



package capture2;

class R<T extends R<T>> {
    T f() { return null; }
    T t;

    void x(R<?> r) {
        this.t = r.f().t; 
    }
}
