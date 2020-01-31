



import java.nio.file.Paths;


public class InnerClassFileTest {

    private static final String BSrc =
        "package x;\n" +
        "\n" +
        "import x.*;\n" +
        "\n" +
        "public class B {\n" +
        "    public static class C {}\n" +
        "}";

    private static final String CSrc =
        "package x;\n" +
        "\n" +
        "import x.*;\n" +
        "\n" +
        "public class C {}";

    private static final String MainSrc =
        "package y;\n" +
        "\n" +
        "class Main {\n" +
        "        private R1 a;\n" +
        "        private R2 b;\n" +
        "        private R3 c;\n" +
        "}";

    private static final String R1Src =
        "package y;\n" +
        "\n" +
        "public final class R1 {\n" +
        "    x.B.C a = null;\n" +
        "    x.C b = null;\n" +
        "    R2 c = new R2();\n" +
        "}";

    private static final String R2Src =
        "package y;\n" +
        "\n" +
        "public final class R2 {\n" +
        "    x.B.C a = null;\n" +
        "    x.C b = null;\n" +
        "}";

    private static final String R3Src =
        "package y;\n" +
        "\n" +
        "public final class R3 {\n" +
        "    x.B.C a = null;\n" +
        "    x.C b = null;\n" +
        "    R1 c = new R1();\n" +
        "}";

    public static void main(String args[]) throws Exception {
        new InnerClassFileTest().run();
    }

    void run() throws Exception {
        createFiles();
        compileFiles();
    }

    void createFiles() throws Exception {


        ToolBox.createJavaFileFromSource(Paths.get("src"), BSrc);
        ToolBox.createJavaFileFromSource(Paths.get("src"), CSrc);
        ToolBox.createJavaFileFromSource(Paths.get("src"), MainSrc);
        ToolBox.createJavaFileFromSource(Paths.get("src"), R1Src);
        ToolBox.createJavaFileFromSource(Paths.get("src"), R2Src);
        ToolBox.createJavaFileFromSource(Paths.get("src"), R3Src);
    }

    void compileFiles() throws Exception {


        ToolBox.JavaToolArgs args =
                new ToolBox.JavaToolArgs()
                .setAllArgs("-d", ".", "-cp" , ".", "-sourcepath", "src",
                "src/x/B.java", "src/x/C.java", "src/y/Main.java");
        ToolBox.javac(args);


        ToolBox.rm(Paths.get("y", "R3.class"));



        args.setAllArgs("-d", ".", "-cp", ".", "-sourcepath", "src", "src/y/Main.java");
        ToolBox.javac(args);
    }

}
