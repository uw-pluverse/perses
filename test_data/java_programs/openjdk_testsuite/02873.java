



class TargetType34<X> {

    TargetType34(X x) {}

    Object next;

    void test() {
        new TargetType34<>(next==null ? null : null);
    }
}
