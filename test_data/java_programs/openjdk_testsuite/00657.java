



import com.sun.tools.javac.util.Assert;
import java.util.ArrayList;
import java.util.List;

public class CheckRejectProfileBCPOptionsIfUsedTogetherTest {

    private static final String TestSrc =
        "public class Test {\n" +
        "    javax.swing.JButton b;\n" +
        "}";

    public static void main(String args[]) throws Exception {
        List<String> errOutput = new ArrayList<>();
        String testJDK = ToolBox.jdkUnderTest;
        ToolBox.createJavaFileFromSource(TestSrc);

        ToolBox.AnyToolArgs javacParams =
                new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(ToolBox.javacBinary)
                .appendArgs(ToolBox.testToolVMOpts)
                .appendArgs("-profile", "compact1", "-bootclasspath",
                testJDK + "/jre/lib/rt.jar", "Test.java")
                .setErrOutput(errOutput);

        ToolBox.executeCommand(javacParams);

        Assert.check(errOutput.get(0).startsWith(
                "javac: profile and bootclasspath options cannot be used together"),
                "Incorrect javac error output");
    }

}
