


public class T6531090a {

    static class E {}

    static class F extends E implements I1 {}

    static interface I {}

    static interface I1 {}

    static class G extends F implements I {}

    static class C<T extends E & I> {
        T field;
    }

    public static void main(String... args) {
        test(new C<G>());
    }

    static <W extends F> void test(C<? extends W> arg) {
        F vf = arg.field;
        I vi = arg.field;
        I1 vi1 = arg.field;
        E ve = arg.field;
        W vt = arg.field;
    }
}
