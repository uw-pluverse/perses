



import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;


public class ClassPathTest {

    private static final String ClassPathTest1Src =
        "import pkg.*;\n" +
        "public class ClassPathTest1 {\n" +
        "    ClassPathTestAux1 x;\n" +
        "}";

    private static final String ClassPathTest2Src =
        "import pkg.*;\n" +
        "public class ClassPathTest2 {\n" +
        "    ClassPathTestAux2 x;\n" +
        "}";

    private static final String ClassPathTest3Src =
        "import pkg.*;\n" +
        "public class ClassPathTest3 {\n" +
        "    ClassPathTestAux3 x;\n" +
        "}";

    private static final String fooPkgClassPathTestAux1Src =
        "package pkg;\n" +
        "public class ClassPathTestAux1 {}";

    private static final String barPkgClassPathTestAux2Src =
        "package pkg;\n" +
        "public class ClassPathTestAux2 {}";

    private static final String pkgClassPathTestAux3Src =
        "package pkg;\n" +
        "public class ClassPathTestAux3 {}";

    ProcessBuilder pb = null;

    public static void main(String[] args) throws Exception {
        new ClassPathTest().test();
    }

    public void test() throws Exception {
        createOutputDirAndSourceFiles();
        checkCompileCommands();
    }

    void createOutputDirAndSourceFiles() throws Exception {
        
        ToolBox.createJavaFileFromSource(ClassPathTest1Src);
        ToolBox.createJavaFileFromSource(ClassPathTest2Src);
        ToolBox.createJavaFileFromSource(ClassPathTest3Src);
        ToolBox.createJavaFileFromSource(Paths.get("foo"),
                fooPkgClassPathTestAux1Src);
        ToolBox.createJavaFileFromSource(Paths.get("bar"),
                barPkgClassPathTestAux2Src);
        ToolBox.createJavaFileFromSource(pkgClassPathTestAux3Src);
    }

    void checkCompileCommands() throws Exception {





        List<String> mainArgs = new ArrayList<>();
        mainArgs.add(ToolBox.javacBinary.toString());
        if (ToolBox.testToolVMOpts != null) {
            mainArgs.addAll(ToolBox.testToolVMOpts);
        }

        List<String> commonArgs = new ArrayList<>();
        commonArgs.addAll(mainArgs);
        commonArgs.addAll(Arrays.asList("-cp", "."));

        ToolBox.AnyToolArgs successParams = new ToolBox.AnyToolArgs()
                .appendArgs(commonArgs)
                .appendArgs("ClassPathTest3.java");
        ToolBox.executeCommand(successParams);


        ToolBox.AnyToolArgs failParams =
                new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(commonArgs)
                .appendArgs("ClassPathTest1.java");
        ToolBox.executeCommand(failParams);




        Map<String, String> extVars = new TreeMap<>();
        extVars.put("CLASSPATH", "bar");


        successParams = new ToolBox.AnyToolArgs()
                .appendArgs(mainArgs)
                .appendArgs("ClassPathTest2.java")
                .set(extVars);
        ToolBox.executeCommand(successParams);


        failParams = new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(mainArgs)
                .appendArgs("ClassPathTest1.java")
                .set(extVars);
        ToolBox.executeCommand(failParams);


        failParams = new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(mainArgs)
                .appendArgs("ClassPathTest3.java")
                .set(extVars);
        ToolBox.executeCommand(failParams);



        commonArgs.clear();
        commonArgs.addAll(mainArgs);
        commonArgs.addAll(Arrays.asList("-cp", "foo"));

        successParams = new ToolBox.AnyToolArgs()
                .appendArgs(commonArgs)
                .appendArgs("ClassPathTest1.java")
                .set(extVars);
        ToolBox.executeCommand(successParams);


        failParams = new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(commonArgs)
                .appendArgs("ClassPathTest2.java")
                .set(extVars);
        ToolBox.executeCommand(failParams);


        failParams = new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(commonArgs)
                .appendArgs("ClassPathTest3.java")
                .set(extVars);
        ToolBox.executeCommand(failParams);
    }

}
