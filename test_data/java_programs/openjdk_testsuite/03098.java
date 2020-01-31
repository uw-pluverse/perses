

class TargetType13 {

    interface SAM<E extends Throwable> {
       void m(Integer x) throws E;
    }

    static <E extends Throwable> void call(SAM<E> s) throws E { }

    void test() {
        call(i -> { if (i == 2) throw new Exception(); return; });
    }
}
