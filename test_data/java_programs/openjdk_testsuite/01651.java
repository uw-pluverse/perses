

import java.util.*;

class SubTest {

    interface Foo {}
    static class X1 extends Exception implements Foo {}
    static class X2 extends Exception implements Foo {}

    void test(boolean cond, List<String> ls) {
        try {
            if (cond)
                throw new X1();
            else
                throw new X2();
        }
        catch (X1 | X2 ex) {}
    }
}
