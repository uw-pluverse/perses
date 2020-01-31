





public class ProtectedInnerClassesTest {

    private static final String protectedInnerClass1Src =
        "package p1;\n" +
        "\n" +
        "public class ProtectedInnerClass1 {\n" +
        "    protected class Foo {\n" +
        "        public String getBar() { return \"bar\"; }\n" +
        "    }\n" +
        "}";

    private static final String protectedInnerClass2Src =
        "package p2;\n" +
        "\n" +
        "public class ProtectedInnerClass2 extends p1.ProtectedInnerClass1\n" +
        "{\n" +
        "    class Bug extends Foo {\n" +
        "        String getBug() { return getBar(); }\n" +
        "    }\n" +
        "\n" +
        "    public static void main(String[] args) {\n" +
        "        ProtectedInnerClass2 x = new ProtectedInnerClass2();\n" +
        "        Bug y = x.new Bug();\n" +
        "        System.out.println(y.getBug());\n" +
        "    }\n" +
        "}";

    private static final String protectedInnerClass3Src =
        "package p2;\n" +
        "\n" +
        "public class ProtectedInnerClass3 {\n" +
        "\n" +
        "  void test() {\n" +
        "    p1.ProtectedInnerClass1.Foo x;\n" +
        "  }\n" +
        "\n" +
        "}";

    public static void main(String args[]) throws Exception {
        new ProtectedInnerClassesTest().run();
    }

    void run() throws Exception {
        compileAndExecute();
        compileOnly();
    }

    void compileAndExecute() throws Exception {

        ToolBox.JavaToolArgs javacParams =
                new ToolBox.JavaToolArgs()
                .setOptions("-d", ".")
                .setSources(protectedInnerClass1Src, protectedInnerClass2Src);

        ToolBox.javac(javacParams);


        ToolBox.AnyToolArgs javaParams =
                new ToolBox.AnyToolArgs()
                .appendArgs(ToolBox.javaBinary)
                .appendArgs(ToolBox.testVMOpts)
                .appendArgs("-classpath", System.getProperty("user.dir"),
                    "p2.ProtectedInnerClass2");
        ToolBox.executeCommand(javaParams);
    }


    void compileOnly() throws Exception {

        ToolBox.JavaToolArgs javacParams =
                new ToolBox.JavaToolArgs()
                .appendArgs("-d", ".")
                .setSources(protectedInnerClass1Src);

        ToolBox.javac(javacParams);


        javacParams = new ToolBox.JavaToolArgs(ToolBox.Expect.FAIL)
                .appendArgs("-d", ".")
                .setSources(protectedInnerClass3Src);
        ToolBox.javac(javacParams);
    }

}
