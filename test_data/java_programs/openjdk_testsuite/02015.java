



public class CompilerCrashWhenMixingBinariesAndSourcesTest {
    private static final String ASource =
            "class A {\n" +
            "        void test() {new B(){};}\n" +
            "}";
    private static final String BSource =
            "class B extends C {}";
    private static final String CSource =
            "class C extends D {\n" +
            "        String m(int i) {return null;}\n" +
            "}";
    private static final String DSource =
            "class D {\n" +
            "        Object m(int i) {return null;}\n" +
            "}";

    public static void main (String[] args) throws Exception{
        ToolBox.JavaToolArgs javacParams = new ToolBox.JavaToolArgs()
                .setSources(ASource, BSource, CSource, DSource);
        ToolBox.javac(javacParams);

        ToolBox.rm("A.class");
        ToolBox.rm("A$1.class");
        ToolBox.rm("C.class");
        ToolBox.rm("D.class");

        javacParams = new ToolBox.JavaToolArgs()
                .setOptions("-cp", ".")
                .setSources(ASource, CSource, DSource);
        ToolBox.javac(javacParams);
    }
}
