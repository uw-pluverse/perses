



import com.sun.source.tree.*;
import com.sun.source.util.*;
import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import javax.tools.*;



@SupportedOptions("scan")
@SupportedAnnotationTypes("*")
public class TestDocComments extends AbstractProcessor {
    enum CompileKind { API, CMD };
    enum ScanKind { TREE, ELEMENT };

    

    public static void main(String... args) throws Exception {
        for (CompileKind ck: CompileKind.values()) {
            for (ScanKind sk: ScanKind.values()) {
                try {
                    test(ck, sk);
                } catch (IOException e) {
                    error(e.toString());
                }
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    static void test(CompileKind ck, ScanKind sk) throws IOException {
        String testClasses = System.getProperty("test.classes");
        String testSrc = System.getProperty("test.src");
        File testDir = new File("test." + ck + "." + sk);
        testDir.mkdirs();
        String[] opts = {
            "-d", testDir.getPath(),
            "-implicit:none",
            "-processor", TestDocComments.class.getName(),
            "-processorpath", testClasses,
            
            "-Ascan=" + sk
        };
        File[] files = {
            new File(testSrc, "a/First.java")
        };

        if (ck == CompileKind.API)
            test_javac_api(opts, files);
        else
            test_javac_cmd(opts, files);
    }

    static void test_javac_api(String[] opts, File[] files) throws IOException {
        System.err.println("test javac api: " + Arrays.asList(opts) + " " + Arrays.asList(files));
        DiagnosticListener<JavaFileObject> dl = new DiagnosticListener<JavaFileObject>() {
            public void report(Diagnostic diagnostic) {
                error(diagnostic.toString());
            }
        };
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> units = fm.getJavaFileObjects(files);
        JavacTask t = (JavacTask) c.getTask(null, fm, dl, Arrays.asList(opts), null, units);
        t.parse();
        t.analyze();
    }

    static void test_javac_cmd(String[] opts, File[] files) {
        System.err.println("test javac cmd: " + Arrays.asList(opts) + " " + Arrays.asList(files));
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        List<String> args = new ArrayList<String>(Arrays.asList(opts));
        for (File f: files)
            args.add(f.getPath());
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.close();
        String out = sw.toString();
        if (out.length() > 0)
            System.err.println(out);
        if (rc > 0)
            error("Compilation failed: rc=" + rc);
    }

    static void error(String msg) {
        System.err.println(msg);
        errors++;
        
    }

    static int errors;

    

    Map<String,String> options;
    Filer filer;
    Messager messager;
    Elements elements;
    Trees trees;
    ScanKind skind;

    int round = 0;

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public void init(ProcessingEnvironment pEnv) {
        super.init(pEnv);
        options = pEnv.getOptions();
        filer = pEnv.getFiler();
        messager = pEnv.getMessager();
        elements = pEnv.getElementUtils();
        trees = Trees.instance(processingEnv);
        skind = ScanKind.valueOf(options.get("scan"));
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        round++;

        
        
        for (Element e: roundEnv.getRootElements()) {
            System.err.println("scan " + skind + " " + e.getKind() + " " + e.getSimpleName());
            if (skind == ScanKind.TREE) {
                new TestTreeScanner().scan(trees.getPath(e), trees);
            }  else
                new TestElementScanner().scan(e);
        }

        
        
        final int MAX_ROUNDS = 3;
        if (round <= MAX_ROUNDS) {
            String pkg = "p";
            String currClass = "Gen" + round;
            String curr = pkg + "." + currClass;
            String next = (round < MAX_ROUNDS) ? (pkg + ".Gen" + (round + 1)) : "z.Last";
            StringBuilder text = new StringBuilder();
            text.append("package ").append(pkg).append(";\n");
            text.append("/** CLASS ").append(currClass).append(" */\n");
            text.append("public class ").append(currClass).append(" {\n");
            text.append("    /** CONSTRUCTOR <init> **/\n");
            text.append("    ").append(currClass).append("() { }\n");
            text.append("    /** FIELD x */\n");
            text.append("    ").append(next).append(" x;\n");
            text.append("    /** METHOD m */\n");
            text.append("    void m() { }\n");
            text.append("}\n");

            try {
                JavaFileObject fo = filer.createSourceFile(curr);
                Writer out = fo.openWriter();
                try {
                    out.write(text.toString());
                } finally {
                    out.close();
                }
            } catch (IOException e) {
                throw new Error(e);
            }
        }

        return true;
    }

    
    void check(Element e) {
        System.err.println("Checking " + e);

        String dc = elements.getDocComment(e);
        System.err.println("   found " + dc);

        String expect = (e.getKind() + " " + e.getSimpleName()); 

        Name name = e.getSimpleName();
        Element encl = e.getEnclosingElement();
        Name enclName = encl.getSimpleName();
        ElementKind enclKind = encl.getKind();
        switch (e.getKind()) {
            case PARAMETER:
            case LOCAL_VARIABLE:
                
                expect = null;
                break;

            case CONSTRUCTOR:
                if (enclName.length() == 0 || enclKind == ElementKind.ENUM) {
                    
                    expect = null;
                }
                break;

            case METHOD:
                if (enclKind == ElementKind.ENUM
                        && (name.contentEquals("values") || name.contentEquals("valueOf"))) {
                    
                    expect = null;
                }
                break;

            case CLASS:
                if (e.getSimpleName().length() == 0) {
                    
                    expect = null;
                }
                break;
        }

        System.err.println("  expect " + expect);

        if (dc == null ? expect == null : dc.trim().equals(expect))
            return;

        if (dc == null)
            messager.printMessage(Diagnostic.Kind.ERROR, "doc comment is null", e);
        else {
            messager.printMessage(Diagnostic.Kind.ERROR,
                    "unexpected comment: \"" + dc + "\", expected \"" + expect + "\"", e);
        }
    }

    

    class TestElementScanner extends ElementScanner7<Void, Void> {
        @Override
        public Void visitExecutable(ExecutableElement e, Void _) {
            check(e);
            return super.visitExecutable(e, _);
        }
        @Override
        public Void visitType(TypeElement e, Void _) {
            check(e);
            return super.visitType(e, _);
        }
        @Override
        public Void visitVariable(VariableElement e, Void _) {
            check(e);
            return super.visitVariable(e, _);
        }
    }

    class TestTreeScanner extends TreePathScanner<Void,Trees> {
        @Override
        public Void visitClass(ClassTree tree, Trees trees) {
            check(trees.getElement(getCurrentPath()));
            return super.visitClass(tree, trees);
        }
        @Override
        public Void visitMethod(MethodTree tree, Trees trees) {
            check(trees.getElement(getCurrentPath()));
            return super.visitMethod(tree, trees);
        }
        @Override
        public Void visitVariable(VariableTree tree, Trees trees) {
            check(trees.getElement(getCurrentPath()));
            return super.visitVariable(tree, trees);
        }
    }

}
