



import java.util.ArrayList;
import java.util.List;


public class NoJavaLangTest {

    private static final String noJavaLangSrc =
        "public class NoJavaLang {\n" +
        "    private String s;\n" +
        "\n" +
        "    public String s() {\n" +
        "        return s;\n" +
        "    }\n" +
        "}";

    private static final String compilerErrorMessage =
        "Fatal Error: Unable to find package java.lang in classpath or bootclasspath";

    public static void main(String[] args) throws Exception {

        ToolBox.JavaToolArgs javacSuccessArgs =
                new ToolBox.JavaToolArgs().setSources(noJavaLangSrc);
        ToolBox.javac(javacSuccessArgs);


        List<String> output = new ArrayList<>();
        ToolBox.JavaToolArgs javacFailArgs =
                new ToolBox.JavaToolArgs(ToolBox.Expect.FAIL)
                .setOptions("-bootclasspath", ".")
                .setSources(noJavaLangSrc)
                .setErrOutput(output);

        int cr = ToolBox.javac(javacFailArgs);
        if (cr != 3) {
            throw new AssertionError("Compiler exit result should be 3");
        }


        if (!(output.size() == 1 && output.get(0).equals(compilerErrorMessage))) {
            throw new AssertionError("javac generated error output is not correct");
        }
    }

}
