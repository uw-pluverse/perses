




import java.util.Arrays;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;
import javax.tools.Diagnostic;



public class BasicSyntaxCombo extends Helper{
    static int errors = 0;
    static boolean exitMode = false;
    static String TESTPKG = "testpkg";
    static String srcContent = "";
    static String pkgInfoContent = "";

    static {
        
        String exitOnFail = System.getenv("EXIT_ON_FAIL");
        if (exitOnFail == null || exitOnFail == ""  ) {
            exitMode = false;
        }
        else {
            if (exitOnFail.equalsIgnoreCase("YES") ||
                    exitOnFail.equalsIgnoreCase("Y") ||
                    exitOnFail.equalsIgnoreCase("TRUE") ||
                    exitOnFail.equalsIgnoreCase("T")) {
                exitMode = true;
            }
        }
    }

    enum TestElem {
        ANNOTATION_TYPE(true),
        PACKAGE(true),
        CONSTRUCTOR(true),
        FIELD(true),
        LOCAL_VARIABLE(true),
        METHOD(true),
        TYPE(true),
        PARAMETER(true),
        INNER_CLASS(true),
        STATIC_INI(false),
        INSTANCE_INI(false);

        TestElem(boolean compile) {
            this.compile = compile;
        }

        boolean compile;
        boolean shouldCompile() {
            return compile;
        }
    }

    public static void main(String[] args) throws Exception {
        new BasicSyntaxCombo().runTest();
    }

    public void runTest() throws Exception {
        boolean result = false;
        Iterable<? extends JavaFileObject> files = null;
        int testCtr = 0;
        for (TestElem type : TestElem.values()) {
            testCtr++;
            String className = "BasicCombo_"+type;
            files = getFileList(className, type);

            boolean shouldCompile = type.shouldCompile();
            result = getCompileResult(className, shouldCompile,files);

            if (shouldCompile && !result) {
                error(className + " did not compile as expected", srcContent);
                if(!pkgInfoContent.isEmpty()) {
                    System.out.println("package-info.java contents: " + pkgInfoContent);
                }
            }

            if (!shouldCompile && !result) {
                error(className + " compiled unexpectedly", srcContent);
                if(!pkgInfoContent.isEmpty()) {
                    System.out.println("package-info.java contents: " + pkgInfoContent);
                }
            }
        }

        System.out.println("Total number of tests run: " + testCtr);
        System.out.println("Total number of errors: " + errors);

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    private boolean getCompileResult(String className, boolean shouldCompile,
            Iterable<? extends JavaFileObject> files) throws Exception {

        DiagnosticCollector<JavaFileObject> diagnostics =
                new DiagnosticCollector<JavaFileObject>();
        boolean ok =  Helper.compileCode(diagnostics,files);
        if (!shouldCompile && !ok) {
            checkErrorKeys(className, diagnostics);
        }
        return (shouldCompile == ok);
    }

    private void checkErrorKeys (
            String className, DiagnosticCollector<JavaFileObject> diagnostics) throws Exception {
        String expectedErrKey = "compiler.err.illegal.start.of.type";
        for (Diagnostic<?> d : diagnostics.getDiagnostics()) {
            if ((d.getKind() == Diagnostic.Kind.ERROR) &&
                d.getCode().contains(expectedErrKey)) {
                break; 
            } else {
                error("Incorrect error key, expected = "
                      + expectedErrKey + ", Actual = " + d.getCode()
                      + " for className = " + className, srcContent);
            }
        }
    }

    private Iterable<? extends JavaFileObject> getFileList(String className,
            TestElem type ) {

        String template = Helper.template;
        String replaceStr = "/*"+type+"*/";
        StringBuilder annoData = new StringBuilder();
        annoData.append(Helper.ContentVars.IMPORTCONTAINERSTMTS.getVal())
                .append(Helper.ContentVars.CONTAINER.getVal())
                .append(Helper.ContentVars.REPEATABLE.getVal())
                .append(Helper.ContentVars.BASE.getVal());

        JavaFileObject pkgInfoFile = null;

        if (type.equals("PACKAGE")) {
            srcContent = template.replace(replaceStr, "package testpkg;")
                        .replace("#ClassName", className);

            String pkgInfoName = TESTPKG+"."+"package-info";
            pkgInfoContent = Helper.ContentVars.REPEATABLEANNO.getVal()
                             + "package " + TESTPKG + ";"
                             + annoData;
            pkgInfoFile = getFile(pkgInfoName, pkgInfoContent);
        } else {
            template = template.replace(replaceStr, Helper.ContentVars.REPEATABLEANNO.getVal())
                       .replace("#ClassName", className);
            srcContent = annoData + template;
        }

        JavaFileObject srcFile = getFile(className, srcContent);

        Iterable<? extends JavaFileObject> files = null;
        if (pkgInfoFile != null) {
            files = Arrays.asList(pkgInfoFile,srcFile);
        }
        else {
            files = Arrays.asList(srcFile);
        }
        return files;
    }

    private void error(String msg, String... contents) throws Exception {
        System.out.println("error: " + msg);
        errors++;
        if (contents.length == 1) {
            System.out.println("Contents = " + contents[0]);
        }
        
        if (exitMode) throw new Exception();
    }
}
