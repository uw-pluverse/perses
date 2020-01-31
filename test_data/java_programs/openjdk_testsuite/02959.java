



import java.util.function.Function;


public class MethodRefNewInnerInLambdaVerify2 {
    public static void main(String[] args) { new MethodRefNewInnerInLambdaVerify2().runTest(); }

    private void runTest() {
        Worker worker = new Worker();
        run(() -> worker.check(field -> new SomeClass(field)));
        run(() -> worker.check(SomeClass::new));
    }

    private void run(Runnable runnable) {
        runnable.run();
    }

    private class SomeClass {
        final Object field;

        SomeClass(Object field) {
            this.field = field;
        }
    }

    private static class Worker {
        void check(Function<Object, SomeClass> i) {
            if (!i.apply("frank").field.equals("frank")) throw new AssertionError("sanity failed");
        }
    }
}
