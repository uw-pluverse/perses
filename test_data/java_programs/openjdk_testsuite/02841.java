



import java.io.File;
import java.nio.file.Paths;


public class AssertionFailureTest {

    private static final String testSrc =
        "import stub_tie_gen.wsdl_hello_lit.client.*;\n" +
        "import junit.framework.*;\n" +
        "import testutil.ClientServerTestUtil;\n" +
        "\n" +
        "public class Test {\n" +
        "\n" +
        "    void getStub() throws Exception {\n" +
        "        Hello_PortType_Stub x = null;\n" +
        "        new ClientServerTestUtil().setTransport(x, null, null, null);\n" +
        "    }\n" +
        "\n" +
        "    public static void main(String[] args) {\n" +
        "        System.out.println(\"FISK\");\n" +
        "    }\n" +
        "}";

    public static void main(String args[]) throws Exception {
        String classpath = Paths.get(System.getProperty("test.src"), "broken.jar")
                .toString();
        classpath = new StringBuilder(classpath)
                .append(File.pathSeparator).append(".").toString();

        ToolBox.JavaToolArgs params =
                new ToolBox.JavaToolArgs()
                .setOptions("-cp", classpath)
                .setSources(testSrc);
        ToolBox.javac(params);
    }

}
