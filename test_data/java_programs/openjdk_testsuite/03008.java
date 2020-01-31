

public class TargetType02 {

    interface S1<X extends Number> {
        X m(Integer x);
    }

    interface S2<X extends String> {
        abstract X m(Integer x);
    }

    static <Z extends Number> void call1(S1<Z> s) { }

    static <Z extends String> void call2(S2<Z> s) { }

    static <Z extends Number> void call3(S1<Z> s) { }
    static <Z extends String> void call3(S2<Z> s) { }

    static <Z extends Number> Z call4(S1<Z> s) { return null; }
    static <Z extends String> Z call4(S2<Z> s) { return null; }

    void test() {
        call1(i -> { toString(); return i; });
        call2(i -> { toString(); return i; });
        call3(i -> { toString(); return i; });
        call3(i -> {
            toString();
            return call4(j -> {
                return j;
            });
        });
    }
}
