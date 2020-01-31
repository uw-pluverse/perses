





class EASuper {
    static {
        EarlyAssert.foo();
    }
}

public class EarlyAssert extends EASuper {
    static public void foo() {
        boolean assertionStatus = false;
        assert assertionStatus = true;
        if (!assertionStatus) {
            throw new Error("Assertions are not enabled before initialization as they should be.");
        }
    }
    public static void main(String[] args) {
        boolean assertionStatus = false;
        assert assertionStatus = true;
        if (assertionStatus) {
            throw new Error("Assertions are not disabled after initialization as they should be.");
        }
    }
}
