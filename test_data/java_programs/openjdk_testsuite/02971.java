



import java.util.*;

public class LambdaConv16 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface A {
        Iterable m(List<String> ls);
    }

    interface B {
        Iterable<String> m(List l);
    }

    interface AB extends A, B {} 

    static void test(AB ab, List l) { ab.m(l); }

    public static void main(String[] args) {
        AB ab = (List list) -> { assertTrue(true); return new ArrayList<String>(); };
        ab.m(null);
        test((List list) -> { assertTrue(true); return new ArrayList<String>(); }, null);
        assertTrue(assertionCount == 2);
    }
}
