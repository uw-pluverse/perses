
class TargetType49 {

    interface F {
        default Object clone() { return null; }
        void m();
    }

    F f1 = ()->{};
    F f2 = this::g;

    void g() { }
}
