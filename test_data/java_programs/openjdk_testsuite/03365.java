



public class TopLevelClassStaticMethodArgs extends NumArgsTest {
    private TopLevelClassStaticMethodArgs() {
        super(255, true, "void", "test", "TopLevelClassStaticMethodArgs");
    }

    public static void main(String... args) throws Exception {
        new TopLevelClassStaticMethodArgs().runTest();
    }
}
