



public class AllowEnclosingVarCaptureTest {

    int var = 0;

    void foo() {
        var *= 2;
    }

    public static void main(String[] args) {
        new AllowEnclosingVarCaptureTest().new Inner(9764);
    }

    public class Inner {
        public Inner(Runnable r) {
            r.run();
            if (var != 66704)
                throw new AssertionError("Unexpected output: " + var);
        }

        public Inner(int x) {
            this(() -> {
                var = x + 1234;
                AllowEnclosingVarCaptureTest.this.var += 5678;
                foo();
                AllowEnclosingVarCaptureTest.this.foo();
            });
        }
    }
}
