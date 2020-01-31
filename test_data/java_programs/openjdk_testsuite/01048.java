



public class IncorrectInheritanceTest {
    private static final String ASrc =
            "package pkg;\n" +
            "\n" +
            "public class A {\n" +
            "    static void foo(Object o) {}\n" +
            "    private static void bar(Object o) {}\n" +
            "}";

    private static final String BSrc =
            "import pkg.A;\n" +
            "class B extends A {\n" +
            "    public void foo(Object o) {}\n" +
            "    public void bar(Object o) {}\n" +
            "}";

    private static final String CSrc =
            "class C extends B {\n" +
            "    public void m(Object o) {\n" +
            "        foo(o);\n" +
            "        bar(o);\n" +
            "    }\n" +
            "}";

    public static void main(String[] args) throws Exception {
        new IncorrectInheritanceTest().test();
    }

    public void test() throws Exception {
        ToolBox.JavaToolArgs javacParams =
                new ToolBox.JavaToolArgs()
                .setSources(ASrc, BSrc, CSrc);
        ToolBox.javac(javacParams);
    }

}
