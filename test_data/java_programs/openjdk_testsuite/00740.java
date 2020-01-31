

package evalexpr;

import java.lang.reflect.Method;
import java.util.*;
import javax.swing.JOptionPane;
import javax.tools.*;
import static javax.tools.StandardLocation.CLASS_OUTPUT;


public class CompileFromString {

    
    private final static String CLASS_NAME = "EvalExpression";

    
    public final static Object ERROR = new Object() {
        public String toString() { return "error"; }
    };

    
    public static Object evalExpression(JavaCompiler compiler,
                                        DiagnosticListener<JavaFileObject> listener,
                                        List<String> flags,
                                        String expression)
        throws Exception
    {
        
        MemoryFileManager mfm =
            new MemoryFileManager(compiler.getStandardFileManager(listener, null, null));

        
        JavaFileObject fileObject = mfm.makeSource(CLASS_NAME,
            "public class " + CLASS_NAME + " {\n" +
            "    public static Object eval() throws Throwable {\n" +
            "        return " + expression + ";\n" +
            "    }\n}\n");

        JavaCompiler.CompilationTask task =
            compiler.getTask(null, mfm, listener, flags, null, Arrays.asList(fileObject));
        if (task.call()) {
            
            ClassLoader cl = mfm.getClassLoader(CLASS_OUTPUT);
            
            Class compiledClass = cl.loadClass(CLASS_NAME);
            
            Method eval = compiledClass.getMethod("eval");
            
            return eval.invoke(null);
        } else {
            
            return ERROR;
        }
    }

    
    public static void main(String... args) throws Exception {
        
        final JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        final List<String> compilerFlags = new ArrayList();
        compilerFlags.add("-Xlint:all"); 
        compilerFlags.add("-g:none"); 
        String expression = "System.getProperty(\"java.vendor\")";
        while (true) {
            expression = JOptionPane.showInputDialog("Please enter a Java expression",
                                                     expression);
            if (expression == null)
                return; 
            long time = System.currentTimeMillis();
            Object result = evalExpression(compiler, null, compilerFlags, expression);
            time = System.currentTimeMillis() - time;
            System.out.format("Elapsed time %dms %n", time);
            if (result == ERROR)
                System.out.format("Error compiling \"%s\"%n", expression);
            else
                System.out.format("%s => %s%n", expression, result);
        }
    }
}
