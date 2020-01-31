



import java.io.*;
import java.net.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.util.*;

public class TestAnnotationPackageInfo {
    public static void main(String... args) throws Exception {
        new TestAnnotationPackageInfo().run();
    }

    static class MyFileObject extends SimpleJavaFileObject {
        private String text;
        public MyFileObject(String fileName, String text) {
            super(URI.create("myfo:/" + fileName), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
    }

    public void run() throws Exception {
        final String bootPath = System.getProperty("sun.boot.class.path");
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        assert tool != null;

        JavaFileObject test_java = new MyFileObject("test/Test.java",
            "package test; public @interface Test {\n" +
            "    public int mandatory();\n" +
            "}\n");

        JavaFileObject package_info_java = new MyFileObject("test/package-info.java",
            "@Test package test;");

        DiagnosticCollector<JavaFileObject> coll = new DiagnosticCollector<JavaFileObject>();

        List<String> options = Arrays.asList("-bootclasspath",  bootPath);
        List<? extends JavaFileObject> files = Arrays.asList(test_java, package_info_java);
        JavacTask ct = (JavacTask)tool.getTask(null, null, coll, options, null, files);
        ct.analyze();

        String expectedCode = "compiler.err.annotation.missing.default.value";
        List<Diagnostic<? extends JavaFileObject>> diags = coll.getDiagnostics();
        switch (diags.size()) {
            case 0:
                throw new Exception("no diagnostics reported");
            case 1:
                String code = diags.get(0).getCode();
                if (code.equals(expectedCode))
                    return;
                throw new Exception("unexpected diag: " + diags.get(0));
            default:
                throw new Exception("unexpected diags reported: " + diags);
        }
    }
}
