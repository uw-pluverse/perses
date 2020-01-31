



import java.nio.file.Files;
import java.nio.file.Paths;

public class ExceptionInferenceFromClassFileTest {

    static final String ABSrc =
            "class B {\n" +
            "    public static <E extends Throwable> void t(A<E> a) throws E {\n" +
            "        a.run();\n" +
            "    }\n" +
            "}\n" +

            "interface A<E extends Throwable> {\n" +
            "    void run() throws E;\n" +
            "}";

    static final String CSrc =
            "class C {\n" +
            "    public void d() {\n" +
            "        B.t(null);\n" +
            "    }\n" +
            "}";

    public static void main(String[] args) throws Exception {
        Files.createDirectory(Paths.get("out"));

        ToolBox.JavaToolArgs compileABParams =
                new ToolBox.JavaToolArgs()
                .setOptions("-d", "out")
                .setSources(ABSrc);
        ToolBox.javac(compileABParams);

        ToolBox.JavaToolArgs compileCParams =
                new ToolBox.JavaToolArgs()
                .setOptions("-d", "out", "-cp", "out")
                .setSources(CSrc);
        ToolBox.javac(compileCParams);
    }

}
