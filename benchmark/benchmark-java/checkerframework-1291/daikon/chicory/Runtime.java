package daikon.chicory;

@SuppressWarnings("initialization.fields.uninitialized")
public class Runtime {

    public static void startPure() {
        throw new java.lang.Error();
    }

    public static void endPure() {
        throw new java.lang.Error();
    }
}
