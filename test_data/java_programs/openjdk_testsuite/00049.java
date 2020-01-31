



abstract class CrashImplicitLambdaTest {
    boolean foo() {
        return bar(true, a -> {});
    }

    abstract <T1> T1 bar(T1 t1, S<T1> s);

    interface S<S1> {
        void baz(S1 s1);
    }
}
