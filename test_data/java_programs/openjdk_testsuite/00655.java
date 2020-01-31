



public class OuterParameter_1 {
    void f(final int i) throws Exception {
        class A {
            A() throws Exception {
                class B {
                    B() throws Exception {
                        if (i != 555) throw new Exception();
                    }
                }
            }
        }
    }

    public static void main(String args[]) throws Exception {
        new OuterParameter_1().f(555);
    }
}
