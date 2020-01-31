



import java.io.*;
import java.net.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;

public class T7031108 extends JavacTestingAbstractProcessor {
    public static void main(String... args) throws Exception {
        new T7031108().run();
    }

    
    static final JavaSource pC =
            new JavaSource("p/C.java",
                  "package p;\n"
                + "class C {\n"
                + "    void m() {\n"
                + "        new Runnable() {\n"
                + "            public void run() {\n"
                + "                new Runnable() {\n"
                + "                    public void run() { }\n"
                + "                };\n"
                + "            }\n"
                + "        };\n"
                + "    }\n"
                + "}");

    
    static final JavaSource dummy =
            new JavaSource("Dummy.java",
                "class Dummy { }");

    void run() throws Exception {
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = comp.getStandardFileManager(null, null, null);

        
        File cwd = new File(".");
        fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(cwd));
        compile(comp, fm, null, null, pC);

        
        fm.setLocation(StandardLocation.ANNOTATION_PROCESSOR_PATH,
                fm.getLocation(StandardLocation.CLASS_PATH));
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(cwd));
        compile(comp, fm, null, getClass().getName(), dummy);

        File pC_class = new File(new File("p"), "C.class");
        pC_class.delete();

        DiagnosticCollector<JavaFileObject> dc = new DiagnosticCollector<JavaFileObject>();
        compile(comp, fm, dc, getClass().getName(), dummy);
        List<Diagnostic<? extends JavaFileObject>> diags =dc.getDiagnostics();

        System.err.println(diags);
        switch (diags.size()) {
            case 0:
                throw new Exception("no diagnostics received");
            case 1:
                String code = diags.get(0).getCode();
                String expect = "compiler.err.proc.cant.access.1";
                if (!expect.equals(code))
                    throw new Exception("unexpected diag code: " + code
                            + ", expected: " + expect);
                break;
            default:
                throw new Exception("unexpected diags received");
        }
    }

    void compile(JavaCompiler comp, JavaFileManager fm,
            DiagnosticListener<JavaFileObject> dl,
            String processor, JavaFileObject... files) throws Exception {
        System.err.println("compile processor:" + processor + ", files:" + Arrays.asList(files));
        List<String> opts = new ArrayList<String>();
        if (processor != null) {
            
            opts.addAll(Arrays.asList("-processor", processor));
        }
        CompilationTask task = comp.getTask(null, fm, dl, opts, null, Arrays.asList(files));
        boolean ok = task.call();
        if (dl == null && !ok)
            throw new Exception("compilation failed");
    }

    static class JavaSource extends SimpleJavaFileObject {
        JavaSource(String name, String text) {
            super(URI.create("js://" + name), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
        final String text;
    }

    

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            PackageElement p = elements.getPackageElement("p");
            List<? extends Element> elems = p.getEnclosedElements();
            System.err.println("contents of package p: " + elems);
            if (elems.size() != 1 || !elems.get(0).getSimpleName().contentEquals("C")) {
                messager.printMessage(Diagnostic.Kind.ERROR, "unexpected package contents");
            }
        }
        return true;
    }
}

