



import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class SourceToSourceTranslationTest {

    public static void main(String[] args) throws Exception {
        Path path1 = Paths.get(System.getProperty("test.classes"), "Universe.java");
        Path path2 = Paths.get(System.getProperty("test.src"), "Universe.java.out");
        ToolBox.compareLines(path1, path2, null);
    }

}
