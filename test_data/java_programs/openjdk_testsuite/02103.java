



import java.io.File;
import java.nio.file.Paths;

import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.LineNumberTable_attribute;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.util.Assert;

public class WrongLNTForLambdaTest {

    static final String testSource =
            "import java.util.List;\n" +
            "import java.util.Arrays;\n" +
            "import java.util.stream.Collectors;\n" +
            "\n" +
            "public class Foo {\n" +
            "    void bar(int value) {\n" +
            "        final List<Integer> numbers = Arrays.asList(1, 2, 3);\n" +
            "        final List<Integer> numbersPlusOne = \n" +
            "             numbers.stream().map(number -> number / 1).collect(Collectors.toList());\n" +
            "    }\n" +
            "    void variablesInLambdas(int value) {\n" +
            "        Runnable r1 = () -> {\n" +
            "            int i  = value;\n" +
            "            class FooBar<T extends CharSequence> {\n" +
            "                public void run() {\n" +
            "                    T t = null;\n" +
            "                }\n" +
            "            }\n" +
            "        };\n" +
            "        Runnable r2 = () -> System.err.println(1);\n" +
            "        Runnable r3 = (Runnable & java.io.Serializable) this::foo;\n" +
            "        Runnable r4 = super :: notify;\n" +
            "    }\n" +
            "    private void foo() {}\n" +
            "    void assignLambda() {\n" +
            "        Runnable r = () -> { };\n" +
            "    }\n" +
            "    void callLambda(int i, Runnable r) {\n" +
            "        callLambda(0,\n" +
            "                   () -> { });\n" +
            "    }\n" +
            "}";

    static final int[][] simpleLambdaExpectedLNT = {
    
        {9,           0},       
    };

    static final int[][] lambdaWithVarsExpectedLNT = {
    
        {13,           0},       
        {19,           2},       
    };

    static final int[][] insideLambdaWithVarsExpectedLNT = {
    
        {16,           0},       
        {17,           2},       
    };

    static final int[][] lambdaVoid2VoidExpectedLNT = {
    
        {20,           0},       
    };

    static final int[][] deserializeExpectedLNT = {
    
        {05,           0},       
    };

    static final int[][] lambdaBridgeExpectedLNT = {
    
        {22,           0},       
    };

    static final int[][] assignmentExpectedLNT = {
    
        {26,           0},       
        {27,           6},       
    };

    static final int[][] callExpectedLNT = {
    
        {29,           0},       
        {31,           10},       
    };

    public static void main(String[] args) throws Exception {
        new WrongLNTForLambdaTest().run();
    }

    void run() throws Exception {
        compileTestClass();
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "lambda$bar$0", simpleLambdaExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "lambda$variablesInLambdas$1", lambdaWithVarsExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo$1FooBar.class").toUri()), "run", insideLambdaWithVarsExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "lambda$variablesInLambdas$2", lambdaVoid2VoidExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "$deserializeLambda$", deserializeExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "lambda$variablesInLambdas$3", lambdaBridgeExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "assignLambda", assignmentExpectedLNT);
        checkClassFile(new File(Paths.get(System.getProperty("user.dir"),
                "Foo.class").toUri()), "callLambda", callExpectedLNT);
    }

    void compileTestClass() throws Exception {
        ToolBox.JavaToolArgs javacSuccessArgs =
                new ToolBox.JavaToolArgs().setSources(testSource);
        ToolBox.javac(javacSuccessArgs);
    }

    void checkClassFile(final File cfile, String methodToFind, int[][] expectedLNT) throws Exception {
        ClassFile classFile = ClassFile.read(cfile);
        boolean methodFound = false;
        for (Method method : classFile.methods) {
            if (method.getName(classFile.constant_pool).equals(methodToFind)) {
                methodFound = true;
                Code_attribute code = (Code_attribute) method.attributes.get("Code");
                LineNumberTable_attribute lnt =
                        (LineNumberTable_attribute) code.attributes.get("LineNumberTable");
                Assert.check(lnt.line_number_table_length == expectedLNT.length,
                        "The LineNumberTable found has a length different to the expected one");
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
        Assert.check(methodFound, "The seek method was not found");
    }

    void error(String msg) {
        throw new AssertionError(msg);
    }

}
