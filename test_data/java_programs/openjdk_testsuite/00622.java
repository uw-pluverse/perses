



import java.io.File;
import java.nio.file.Paths;

import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.LineNumberTable_attribute;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.util.Assert;

public class DebugPointerAtBadPositionTest {

    static final String testSource =
            "public class AssertionTest {\n" +
            "    void lookForThisMethod() {\n" +
            "        int i;\n" +
            "        i = 33;\n" +
            "        assert // line 5\n" +
            "            i < 89:\n" +
            "        i < 100; // line 7\n" +
            "    }\n" +
            "}";

    static final int[][] expectedLNT = {
        {4, 0},
        {5, 3},
        {8, 34}
    };

    static final String methodToLookFor = "lookForThisMethod";
    static final String seekMethodNotFoundMsg =
        "The seek method was not found";
    static final String foundLNTLengthDifferentThanExpMsg =
        "The LineNumberTable found has a length different to the expected one";

    public static void main(String[] args) throws Exception {
        new DebugPointerAtBadPositionTest().run();
    }

    void run() throws Exception {
        compileTestClass();
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "AssertionTest.class").toUri()), methodToLookFor);
    }

    void compileTestClass() throws Exception {
        ToolBox.JavaToolArgs javacSuccessArgs =
                new ToolBox.JavaToolArgs().setSources(testSource);
        ToolBox.javac(javacSuccessArgs);
    }

    void checkClassFile(final File cfile, String methodToFind) throws Exception {
        ClassFile classFile = ClassFile.read(cfile);
        boolean methodFound = false;
        for (Method method : classFile.methods) {
            if (method.getName(classFile.constant_pool).equals(methodToFind)) {
                methodFound = true;
                Code_attribute code = (Code_attribute) method.attributes.get("Code");
                LineNumberTable_attribute lnt =
                        (LineNumberTable_attribute) code.attributes.get("LineNumberTable");
                Assert.check(lnt.line_number_table_length == expectedLNT.length,
                        foundLNTLengthDifferentThanExpMsg);
                int i = 0;
                for (LineNumberTable_attribute.Entry entry: lnt.line_number_table) {
                    Assert.check(entry.line_number == expectedLNT[i][0] &&
                            entry.start_pc == expectedLNT[i][1],
                            "LNT entry at pos " + i + " differ from expected." +
                            "Found " + entry.line_number + ":" + entry.start_pc +
                            ". Expected " + expectedLNT[i][0] + ":" + expectedLNT[i][1]);
                    i++;
                }
            }
        }
        Assert.check(methodFound, seekMethodNotFoundMsg);
    }

    void error(String msg) {
        throw new AssertionError(msg);
    }

}
