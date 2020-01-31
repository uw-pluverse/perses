



public class TopLevelClassMethodArgs extends NumArgsTest {
    private TopLevelClassMethodArgs() {
        super(254, "void", "test", "TopLevelClassMethodArgs");
    }

    public static void main(String... args) throws Exception {
        new TopLevelClassMethodArgs().runTest();
    }
}
