



public class LambdaArgumentsTest  {
    interface Thrower<E extends Exception> { void apply() throws E; }
    interface Consumer<E> { void take(E arg); }

    <E extends Exception>
    void m1(Thrower<E> a1, Consumer<E> a2) {}

    <E extends Exception>
    void m2(Thrower<E> a1, Consumer<RuntimeException> a2) {}

    void test() {
        m1(() -> {}, e -> {});
        m2(() -> {}, (RuntimeException e) -> {});
    }
}
