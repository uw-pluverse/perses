

public class Overridden implements Interface {
    public void test() { }
}

interface Interface {
    @Deprecated void test();
}
