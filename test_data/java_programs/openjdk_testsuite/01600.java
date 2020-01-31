



public class ConditionalWithFinalStrings {

        interface I {
            String foo();
        }

        static class Tmp {
                private String value;
                public void setValue(String tmpStr) {
                        this.value = tmpStr;
                        if (!this.value.equals("YES"))
                            throw new AssertionError();
                }
        }

        void goo(I i) {
            if (!i.foo().equals("YES"))
                throw new AssertionError();
        }

        public void test() {
                final String y = "YES";
                final String n = "NO";
                Tmp tmp = new Tmp();
                tmp.setValue(true ? y : n);
                goo (() -> y);

        }
        public static void main(String[] args) {
                new ConditionalWithFinalStrings().test();
                if (!id("Hello!").equals("Hello!"))
                    throw new AssertionError();

        }
        static <Z> Z id(Z z) { return z; }
}
