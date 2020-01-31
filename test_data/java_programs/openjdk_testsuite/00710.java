



import com.sun.source.util.JavacTask;
import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import java.util.List;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;
import static javax.tools.JavaFileObject.Kind;

public class T6608214 {
    public static void main(String[] args) throws IOException {
        JavaFileObject sfo = new SimpleJavaFileObject(URI.create(""),Kind.SOURCE) {
            public CharSequence getCharContent(boolean ignoreEncodingErrors) {
                return "class Test<S> { <T extends S & Runnable> void test(){}}";
            }
        };
        List<? extends JavaFileObject> files = Arrays.asList(sfo);
        String bootPath = System.getProperty("sun.boot.class.path");
        List<String> opts = Arrays.asList("-bootclasspath",  bootPath, "-Xjcov");
        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTask ct = (JavacTask)tool.getTask(null, null, null,opts,null,files);
        ct.analyze();
    }
}
