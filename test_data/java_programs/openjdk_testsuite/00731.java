



import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.main.JavaCompiler;
import java.io.File;
import java.io.IOException;
import javax.lang.model.element.TypeElement;
import javax.tools.ToolProvider;

public class TestResolveIdent {

    @SuppressWarnings("deprecation")
    static Class<?> getDeprecatedClass() {
        return java.io.StringBufferInputStream.class;
    }

    public static void main(String[] args) throws IOException {
        javax.tools.JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTaskImpl task = (JavacTaskImpl)tool.getTask(null, null, null, null, null, null);
        JavaCompiler compiler = JavaCompiler.instance(task.getContext());
        System.out.println(compiler.resolveIdent(getDeprecatedClass().getCanonicalName()));
    }

}
