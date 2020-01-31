



public class NestedClassMethodArgs extends NumArgsTest {
    private static final NumArgsTest.NestingDef[] nesting = {
        classNesting("Inner")
    };

    private NestedClassMethodArgs() {
        super(254, "void", "test", "NestedClassMethodArgs", nesting);
    }

    public static void main(String... args) throws Exception {
        new NestedClassMethodArgs().runTest();
    }
}

