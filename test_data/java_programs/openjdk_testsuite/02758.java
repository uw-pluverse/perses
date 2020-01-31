



import java.io.File;
import java.nio.file.Paths;


public class JavaZipTest {

    private static final String ASrc =
        "class A {\n" +
        "    B b;\n" +
        "}";

    private static final String BGoodSrc =
        "public class B {}";

    private static final String BBadSrc =
        "class B";

    private static final String[][] jarArgs = {
        {"cf", "good.jar", "-C", "good", "B.java"},
        {"cf", "good.zip", "-C", "good", "B.java"},
        {"cf", "bad.jar", "-C", "bad", "B.java"},
        {"cf", "bad.zip", "-C", "bad", "B.java"},
    };

    private static final String[][] successfulCompilationArgs = {
        {"-d", "output", "A.java", "good/B.java"},
        {"-d", "output", "-cp", "good", "A.java"},
        {"-d", "output", "-sourcepath", "good", "A.java"},
        {"-d", "output", "-cp", "good.zip", "A.java"},
        {"-d", "output", "-cp", "good.jar", "A.java"},
    };

    private static final String[][] unSuccessfulCompilationArgs = {
        {"-d", "output", "A.java", "bad/B.java"},
        {"-d", "output", "-cp", "bad", "A.java"},
        {"-d", "output", "-sourcepath", "bad", "A.java"},
        {"-d", "output", "-sourcepath", "bad.zip", "A.java"},
        {"-d", "output", "-sourcepath", "bad.jar", "A.java"},
    };

    public static void main(String[] args) throws Exception {
        new JavaZipTest().test();
    }

    public void test() throws Exception {
        createOutputDirAndSourceFiles();
        createZipsAndJars();
        check(ToolBox.Expect.SUCCESS, successfulCompilationArgs);
        check(ToolBox.Expect.FAIL, unSuccessfulCompilationArgs);
    }

    void createOutputDirAndSourceFiles() throws Exception {
        
        new File("output").mkdir();

        
        ToolBox.createJavaFileFromSource(Paths.get("good"), BGoodSrc);
        ToolBox.createJavaFileFromSource(Paths.get("bad"), BBadSrc);
        ToolBox.createJavaFileFromSource(ASrc);
    }

    void createZipsAndJars() throws Exception {
        




        for (String[] args: jarArgs) {
            ToolBox.jar(args);
        }
    }

    void check(ToolBox.Expect whatToExpect, String[][] theArgs) throws Exception {











        ToolBox.JavaToolArgs args =
                new ToolBox.JavaToolArgs(whatToExpect);

        for (String[] allArgs: theArgs) {
            args.setAllArgs(allArgs);
            ToolBox.javac(args);
        }
    }

}
