



public class LambdaCapture04 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface Tester {
        void test();
    }

    interface TU<U> {
        public void foo(U u);
    }

    public static <U> void exec(TU<U> lambda, U x) {
        lambda.foo(x);
    }

    Integer n1 = 10;

    void test1() {
        final Integer N1 = 1;
        class A {
            Integer n2 = 20;
            void test() {
                  final Integer N2 = 2;
                  class B {
                       void test() {
                           final Integer N3 = 3;
                           exec((final Integer x) -> new Tester() { public void test() { assertTrue(x + n1 + n2 + N1 + N2 + N3 == 66); } }.test(),30);
                       }
                  }
                  new B().test();
            }
        }
        new A().test();
    }

    void test2() {
        final Integer N1 = 1;
        class A {
            Integer n2 = 20;
            void test() {
                  final Integer N2 = 2;
                  class B {
                       void test() {
                           final Integer N3 = 3;
                           exec((final Integer x) -> {
                               class LocTester implements Tester {
                                   public void test() { assertTrue(x + n1 + n2 + N1 + N2 + N3 == 66); }
                               };
                               new LocTester().test();
                           },30);
                       }
                  }
                  new B().test();
            }
        }
        new A().test();
    }

    void test3() {
        final Integer N1 = 1;
        new Tester() {
            Integer n2 = 20;
            public void test() {
                final Integer N2 = 2;
                new Tester() {
                    public void test() {
                        final Integer N3 = 3;
                        exec((final Integer x) -> new Tester() { public void test() { assertTrue(x + n1 + n2 + N1 + N2 + N3 == 66); } }.test(),30);
                    }
                }.test();
            }
        }.test();
    }

    void test4() {
        final Integer N1 = 1;
        new Tester() {
            Integer n2 = 20;
            public void test() {
                final Integer N2 = 2;
                new Tester() {
                    public void test() {
                        final Integer N3 = 3;
                        exec((final Integer x) -> {
                            class LocTester implements Tester {
                                public void test() { assertTrue(x + n1 + n2 + N1 + N2 + N3 == 66); }
                            };
                            new LocTester().test();
                        },30);
                    }
                }.test();
            }
        }.test();
    }

    public static void main(String[] args) {
        LambdaCapture04 t = new LambdaCapture04();
        t.test1();
        t.test2();
        t.test3();
        t.test4();
        assertTrue(assertionCount == 4);
    }
}
