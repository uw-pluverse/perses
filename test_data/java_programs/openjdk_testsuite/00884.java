


public class T7160084b {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond) {
            throw new AssertionError();
        }
    }

    interface Extras {
        static class Enums {
            static class Component {
                Component() { throw new RuntimeException("oops!"); }
            }
        }
    }

    interface Test {
        public class Enums {
            interface Widget {
                enum Component { X, Y };
            }

            enum Component implements Widget, Extras {
                Z;
            };

            public static void test() {
               assertTrue(Component.values().length == 1);
            }
        }
    }

    public static void main(String[] args) {
        Test.Enums.test();
        assertTrue(assertionCount == 1);
    }
}
