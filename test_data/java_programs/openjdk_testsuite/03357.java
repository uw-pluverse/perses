



public class NestedClassConstructorArgs extends NumArgsTest {
    private static final NumArgsTest.NestingDef[] nesting = {
        classNesting("Inner")
    };

    private NestedClassConstructorArgs() {
        super(253, "NestedClassConstructorArgs", "Inner", nesting);
    }

    public static void main(String... args) throws Exception {
        new NestedClassConstructorArgs().runTest();
    }
}

