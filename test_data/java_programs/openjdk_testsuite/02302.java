



import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class CheckEBCDICLocaleTest {

    private static final String TestSrc =
        "public class Test {\n" +
        "    public void test() {\n" +
        "        abcdefg\n" +
        "    }\n" +
        "}";

    private static final String TestOutTemplate =
        "output%1$sTest.java:3: error: not a statement\n" +
        "        abcdefg\n" +
        "        ^\n" +
        "output%1$sTest.java:3: error: ';' expected\n" +
        "        abcdefg\n" +
        "               ^\n" +
        "2 errors\n";

    public static void main(String[] args) throws Exception {
        new CheckEBCDICLocaleTest().test();
    }

    public void test() throws Exception {
        String native2asciiBinary = Paths.get(
                System.getProperty("test.jdk"),"bin", "native2ascii").toString();

        ToolBox.createJavaFileFromSource(TestSrc);
        Files.createDirectory(Paths.get("output"));

        ToolBox.AnyToolArgs nativeCmdParams =
                new ToolBox.AnyToolArgs()
                .appendArgs(native2asciiBinary)
                .appendArgs(ToolBox.testToolVMOpts)
                .appendArgs("-reverse", "-encoding", "IBM1047", "Test.java",
                "output/Test.java");
        ToolBox.executeCommand(nativeCmdParams);

        ToolBox.AnyToolArgs javacParams =
                new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(ToolBox.javacBinary)
                .appendArgs(ToolBox.testToolVMOpts)
                .appendArgs("-J-Duser.language=en",
                "-J-Duser.region=US", "-J-Dfile.encoding=IBM1047",
                "output/Test.java")
                .setErrOutput(new File("Test.tmp"));
        ToolBox.executeCommand(javacParams);

        nativeCmdParams = new ToolBox.AnyToolArgs()
                .appendArgs(native2asciiBinary)
                .appendArgs(ToolBox.testToolVMOpts)
                .appendArgs("-encoding", "IBM1047", "Test.tmp", "Test.out");
        ToolBox.executeCommand(nativeCmdParams);

        String goldenFile = String.format(TestOutTemplate, File.separator);
        ToolBox.compareLines(Paths.get("Test.out"),
                Arrays.asList(goldenFile.split("\n")), null, true);
    }

}
