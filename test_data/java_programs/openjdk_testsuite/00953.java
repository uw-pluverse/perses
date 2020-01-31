



import java.io.File;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.List;


public class NewLineTest {

    public static void main(String args[]) throws Exception {

        File javacErrOutput = new File("output.txt");
        ToolBox.AnyToolArgs cmdArgs =
                new ToolBox.AnyToolArgs(ToolBox.Expect.FAIL)
                .appendArgs(ToolBox.javacBinary)
                .appendArgs(ToolBox.testToolVMOpts)
                .appendArgs("-J-Dline.separator='@'")
                .setErrOutput(javacErrOutput);
        ToolBox.executeCommand(cmdArgs);



        List<String> lines = Files.readAllLines(javacErrOutput.toPath(),
                Charset.defaultCharset());
        if (lines.size() != 1) {
            throw new AssertionError("The compiler output should have one line only");
        }
    }

}
