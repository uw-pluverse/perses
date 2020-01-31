



public class OverriddenSuppressed implements Interface {
    @SuppressWarnings("deprecation")
    public void test() { }
}

interface Interface {
    @Deprecated void test();
}
