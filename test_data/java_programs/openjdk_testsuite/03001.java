
class TargetType39 {

    interface I { }

    interface SAM<A, R> {
        R m(A a);
    }

    <U, V> void call(SAM<U, V> s) { }

    void test(boolean cond, SAM<String, Void> ssv) {
        call(cond ? x-> null : ssv);
        call((String s)-> cond ? x-> null : ssv);
    }
}
