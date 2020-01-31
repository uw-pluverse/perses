



import java.util.*;

public class LambdaConv20 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM<X> {
        X m(List<X> l);
    }

    public static void main(String[] args) {
        SAM<Integer> si1 = l -> l.get(0);
        assertTrue(si1.m(Arrays.asList(1)) == 1);
        SAM<Integer> si2 = l -> { return l.get(0); };
        assertTrue(si2.m(Arrays.asList(1)) == 1);
        assertTrue(assertionCount == 2);
    }
}
