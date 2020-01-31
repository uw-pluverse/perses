


import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;

public class Xprint {
    public static void main(String[] args) {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        javac.run(System.in, null, null,
                  "-Xprint",
                  "com.sun.tools.javac.code.Types",
                  "com.sun.tools.javac.parser.Parser",
                  "java.util.EnumSet");
    }
}
