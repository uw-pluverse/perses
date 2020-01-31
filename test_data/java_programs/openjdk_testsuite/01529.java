




public class MrefInferAndExplicitParams {
    static class Foo<X> {}

    interface Supplier<X> {
        X make();
    }

    Supplier<Foo<String>> sfs = Foo::<Number>new;
}
