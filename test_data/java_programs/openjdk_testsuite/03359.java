



public class TopLevelClassConstructorArgs extends NumArgsTest {
    private TopLevelClassConstructorArgs() {
        super(254, "TopLevelClassConstructorArgs");
    }

    public static void main(String... args) throws Exception {
        new TopLevelClassConstructorArgs().runTest();
    }
}
