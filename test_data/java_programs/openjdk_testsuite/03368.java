



public class StaticNestedClassConstructorArgs extends NumArgsTest {
    private static final NumArgsTest.NestingDef[] nesting = {
        classNesting("StaticInner", true)
    };

    private StaticNestedClassConstructorArgs() {
        super(254, "StaticNestedClassConstructorArgs", "StaticInner", nesting);
    }

    public static void main(String... args) throws Exception {
        new StaticNestedClassConstructorArgs().runTest();
    }
}

