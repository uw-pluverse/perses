




public class MissingIncludeTest {

    private static final String MissingIncludeSrc =
        "class MissingInclude {}";

    public static void main(String[] args) throws Exception {
        ToolBox.createJavaFileFromSource(MissingIncludeSrc);


        ToolBox.JavaToolArgs params =
                new ToolBox.JavaToolArgs(ToolBox.Expect.FAIL)
                .setAllArgs("@/nonexistent_file", "MissingInclude.java");
        ToolBox.javac(params);
    }

}
