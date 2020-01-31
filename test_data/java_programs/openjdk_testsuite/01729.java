
package test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;



public class Assertions {
    interface Inner {
        default void testInner() {
            assert false;
        }
    }

    static class InnerImpl implements Inner {}

    static class OuterImpl implements Outer {}

    static class AnotherInnerImpl implements Another.Inner {}

    public static void main(String... args) {
        Set<String> shouldThrowAssert = new HashSet<String>(Arrays.asList(args));
        try {
            new InnerImpl().testInner();
            if (shouldThrowAssert.contains("Inner")) {
                throw new IllegalStateException("AssertionError expected, but not thrown.");
            }
        } catch (AssertionError e) {
            if (!shouldThrowAssert.contains("Inner")) {
                throw new IllegalStateException("AssertionError not expected, but thrown.");
            }
        }
        try {
            new OuterImpl().testOuter();
            if (shouldThrowAssert.contains("Outer")) {
                throw new IllegalStateException("AssertionError expected, but not thrown.");
            }
        } catch (AssertionError e) {
            if (!shouldThrowAssert.contains("Outer")) {
                throw new IllegalStateException("AssertionError not expected, but thrown.");
            }
        }
        try {
            new AnotherInnerImpl().testAnotherInner();
            if (shouldThrowAssert.contains("Another.Inner")) {
                throw new IllegalStateException("AssertionError expected, but not thrown.");
            }
        } catch (AssertionError e) {
            if (!shouldThrowAssert.contains("Another.Inner")) {
                throw new IllegalStateException("AssertionError not expected, but thrown.");
            }
        }
    }
}

interface Outer {
    default void testOuter() {
        assert false;
    }
}

@interface Another {
    interface Inner {
        default void testAnotherInner() {
            assert false;
        }
    }
}
