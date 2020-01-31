



import java.io.*;
import java.net.URI;
import java.util.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;

public class Test {
    public static void main(String... args) throws Exception {
        new Test().run();
    }

    void run() throws Exception {
        Locale prev = Locale.getDefault();
        Locale.setDefault(Locale.ENGLISH);
        try {
            test(Arrays.<String>asList(),
                    "myfo://test:1: error: cannot find symbol");
            test(Arrays.asList("-XDdiagsFormat=OLD"),
                    "myfo://test:1: cannot find symbol");
            test(Arrays.asList("-XDoldDiags"),
                    "myfo://test:1: cannot find symbol");
        } finally {
            Locale.setDefault(prev);
        }
    }

    void test(List<String> options, String expect) throws Exception {
        System.err.println("test: " + options);
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        JavaFileObject f = new MyFileObject("myfo://test", "class Bad { Missing x; }");
        List<? extends JavaFileObject> files = Arrays.asList(f);
        CompilationTask task = javac.getTask(pw, null, null, options, null, files);
        boolean ok = task.call();
        pw.close();
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (ok)
            throw new Exception("Compilation succeeded unexpectedly");
        if (!out.contains(expect))
            throw new Exception("expected text not found: " + expect);
    }

    class MyFileObject extends SimpleJavaFileObject {
        MyFileObject(String uri, String text) {
            super(URI.create(uri), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public String getName() {
            return uri.toString();
        }
        @Override
        public String getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
        final String text;
    }
}


