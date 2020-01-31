



import java.io.File;
import java.nio.file.Paths;

import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.Code_attribute.Exception_data;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.util.Assert;

public class NoDeadCodeGenerationOnTrySmtTest {

    static final String testSource =
        "public class Test {\n" +
        "    void m1(int arg) {\n" +
        "        synchronized (new Integer(arg)) {\n" +
        "            {\n" +
        "                label0:\n" +
        "                do {\n" +
        "                    break label0;\n" +
        "                } while (arg != 0);\n" +
        "            }\n" +
        "        }\n" +
        "    }\n" +

        "    void m2(int arg) {\n" +
        "        synchronized (new Integer(arg)) {\n" +
        "            {\n" +
        "                label0:\n" +
        "                {\n" +
        "                    break label0;\n" +
        "                }\n" +
        "            }\n" +
        "        }\n" +
        "    }\n" +
        "}";

    static final int[][] expectedExceptionTable = {
    
        {11,           13,         16,          0},
        {16,           19,         16,          0}
    };

    static final String[] methodsToLookFor = {"m1", "m2"};

    public static void main(String[] args) throws Exception {
        new NoDeadCodeGenerationOnTrySmtTest().run();
    }

    void run() throws Exception {
        compileTestClass();
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Test.class").toUri()), methodsToLookFor);
    }

    void compileTestClass() throws Exception {
        ToolBox.JavaToolArgs javacSuccessArgs =
                new ToolBox.JavaToolArgs().setSources(testSource);
        ToolBox.javac(javacSuccessArgs);
    }

    void checkClassFile(final File cfile, String[] methodsToFind) throws Exception {
        ClassFile classFile = ClassFile.read(cfile);
        int numberOfmethodsFound = 0;
        for (String methodToFind : methodsToFind) {
            for (Method method : classFile.methods) {
                if (method.getName(classFile.constant_pool).equals(methodToFind)) {
                    numberOfmethodsFound++;
                    Code_attribute code = (Code_attribute) method.attributes.get("Code");
                    Assert.check(code.exception_table_length == expectedExceptionTable.length,
                            "The ExceptionTable found has a length different to the expected one");
                    int i = 0;
                    for (Exception_data entry: code.exception_table) {
                        Assert.check(entry.start_pc == expectedExceptionTable[i][0] &&
                                entry.end_pc == expectedExceptionTable[i][1] &&
                                entry.handler_pc == expectedExceptionTable[i][2] &&
                                entry.catch_type == expectedExceptionTable[i][3],
                                "Exception table entry at pos " + i + " differ from expected.");
                        i++;
                    }
                }
            }
        }
        Assert.check(numberOfmethodsFound == 2, "Some seek methods were not found");
    }

    void error(String msg) {
        throw new AssertionError(msg);
    }

}
