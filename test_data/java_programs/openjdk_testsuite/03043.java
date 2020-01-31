



public class MethodReference35 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        MethodReference35 invoke();
    }

    MethodReference35() {
        assertTrue(true);
    }

    static MethodReference35 m() {
        assertTrue(true);
        return null;
    }

    public static void main(String[] args) {
        SAM sam1 = ((SAM)() -> { assertTrue(true); return null; })::invoke;
        sam1.invoke();
        SAM sam2 = ((SAM)MethodReference35::new)::invoke;
        sam1.invoke();
        SAM sam3 = ((SAM)MethodReference35::m)::invoke;
        sam1.invoke();
        assertTrue(assertionCount == 3);
    }
}
