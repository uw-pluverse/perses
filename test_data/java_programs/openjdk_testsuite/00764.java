



import java.io.File;
import javax.tools.*;

public class T6407011 {
    public static void main(String... args) {
        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        String srcdir = System.getProperty("test.src");
        File file = new File(srcdir, T6407011.class.getSimpleName() + ".java");
        if (tool.run(null, null, null, "-sourcepath", "/x y z", "-d", ".", file.getPath()) != 0)
            throw new AssertionError("non zero return code from compiler");
    }
}
