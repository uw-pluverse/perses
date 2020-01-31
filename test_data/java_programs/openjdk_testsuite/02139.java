


public interface MethodHandleCrash {
    static<T> void functional(T... input) {
        java.util.function.Consumer<T> c = MethodHandleCrash::functional;
    }
}
