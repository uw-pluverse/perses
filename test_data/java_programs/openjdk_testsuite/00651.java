



import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;


public class LinksTest {

    private static final String BSrc =
        "package a;\n" +
        "\n" +
        "public class B {}";

    private static final String TSrc =
        "class T extends a.B {}";

    public static void main(String args[])
            throws Exception {


        ToolBox.writeFile(Paths.get("tmp/B.java"), BSrc);

        

        try {
            Files.createSymbolicLink(Paths.get("a"), Paths.get("tmp"));
            System.err.println("Created symbolic link");
        } catch (UnsupportedOperationException | IOException e) {
            System.err.println("Problem creating symbolic link: " + e);
            System.err.println("Test cannot continue; test passed by default");
            return;
        }

        
        
        
        ToolBox.JavaToolArgs javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-sourcepath", ".", "-d", ".").setSources(TSrc);
        ToolBox.javac(javacArgs);
    }

}
