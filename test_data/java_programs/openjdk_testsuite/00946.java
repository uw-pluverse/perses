



public class UnverifiableInitForNestedLocalClassTest {

    public static void main(final String[] args) {
        test("test");
    }

    static void test(final String arg) {
        final String inlined = " inlined ";
        class LocalClass {
            String m() {
                return "LocalClass " + arg + inlined;
            }

            class SubClass extends LocalClass {
                @Override
                String m() {
                    return "SubClass " + arg + inlined;
                }
            }

            class SubSubClass extends SubClass {
                @Override
                String m() {
                    return "SubSubClass " + arg + inlined;
                }
            }

            class AnotherLocal {
                class AnotherSub extends LocalClass {
                    @Override
                    String m() {
                        return "AnotherSub " + arg + inlined;
                    }
                }
            }
        }
        System.out.println(new LocalClass().m());
        System.out.println(new LocalClass().new SubClass().m());
        System.out.println(new LocalClass().new SubSubClass().m());
        System.out.println(new LocalClass().new AnotherLocal().new AnotherSub().m());
    }

}
