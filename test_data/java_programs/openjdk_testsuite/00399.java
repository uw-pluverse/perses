



class Err<T> {
    Err<T> get() { return null; }
    void put(Err<T> t) {}

    static void f(Err<? extends String> e) {
        e.put(e.get());
    }
}
