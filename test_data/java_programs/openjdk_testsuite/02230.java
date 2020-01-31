



import java.nio.file.Files;
import java.nio.file.Paths;

public class IncorrectSignatureDeterminationForInnerClassesTest {

    private static final String DSrc =
        "package p1;\n" +

        "public class D<T> {\n" +
        "}\n" +

        "abstract class Q<T> {\n" +
        "    protected void m(M.E e) {}\n" +

        "    public class M extends D<T> {\n" +
        "        public class E {}\n" +
        "    }\n" +
        "}";

    private static final String HSrc =
        "package p1;\n" +

        "public class H {\n" +
        "    static class EQ extends Q<Object> {\n" +
        "        private void m2(M.E item) {\n" +
        "            m(item);\n" +
        "        }\n" +
        "    }\n" +
        "}";

    public static void main(String args[]) throws Exception {
        new IncorrectSignatureDeterminationForInnerClassesTest().run();
    }

    void run() throws Exception {
        compile();
    }

    void compile() throws Exception {
        Files.createDirectory(Paths.get("classes"));

        ToolBox.JavaToolArgs javacParams =
                new ToolBox.JavaToolArgs()
                .appendArgs("-d", "classes")
                .setSources(DSrc);

        ToolBox.javac(javacParams);

        
        javacParams =
                new ToolBox.JavaToolArgs()
                .appendArgs("-d", "classes", "-cp", "classes")
                .setSources(HSrc);
        ToolBox.javac(javacParams);
    }

}
