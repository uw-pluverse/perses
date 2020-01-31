


class T8043926 {
    interface Iface<T1> {}

    static class Impl implements Iface<Impl> {}

    static class Acceptor<T2 extends Iface<T2>> {
        public Acceptor(T2 obj) {}
    }

    void test(Impl impl) {
        Acceptor<?> acceptor1 = new Acceptor<>(impl);
        Acceptor<? extends Object> acceptor2 = new Acceptor<>(impl);
    }
}
