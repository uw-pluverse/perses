



class Defender01 {

    interface A{
        Object m();
        default void n() { E.n(this); }
    }

    static class E{
        static void n(A a){};
    }

    A t = ()-> null;
}
