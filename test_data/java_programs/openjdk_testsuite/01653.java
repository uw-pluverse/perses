



import java.nio.file.Path;
import java.nio.file.Paths;


public class HiddenOptionsShouldUseGivenEncodingTest {

    public static void main(String[] args) throws Exception {


        Path path1 = Paths.get(System.getProperty("test.classes"), "T6302184.java");
        Path path2 = Paths.get(System.getProperty("test.src"), "T6302184.out");
        ToolBox.compareLines(path1, path2, "iso-8859-1");
    }

}
