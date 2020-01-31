



public class PositionTest extends A {
    <E extends Exception> void test(SAM<E> r) throws E {
        test(() -> { System.err.println(str); });
    }
    interface SAM<E extends Exception> {
        public void run() throws E;
    }
    void f() {
        try {
            test(() -> {
                    test(() -> {
                            try {
                                test(() -> { System.err.println(str); });
                                System.err.println(str);
                            } catch (Exception e) {}
                            System.err.println(str);
                        });
                    System.err.println(str);
                });
        } catch (Exception e) { }
    }
    void g() throws Exception {
        test(() -> {
                try {
                    try {
                        test(() -> { System.err.println(str); });
                    } catch (Exception e) {}
                    System.err.println(str);
                } catch (Exception e) {}
                System.err.println(str);
            });
    }
}
