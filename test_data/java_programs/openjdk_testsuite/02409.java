



import java.util.List;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;



public class DeprecatedAnnoCombo extends Helper {
    static int errors = 0;

    enum TestCases {
        DeprecatedonBoth,
        DeprecatedonContainer,
        DeprecatedonBase;
    }

    public static void main(String[] args) throws Exception {
        new DeprecatedAnnoCombo().runTest();
    }

    public void runTest() throws Exception {
        boolean ok = false;
        int testCtr = 0;

        for (TestCases clName : TestCases.values()) {
            testCtr++;

            
            String contents = getContent(clName.toString());

            
            DiagnosticCollector<JavaFileObject> diagnostics =
                    new DiagnosticCollector<JavaFileObject>();
            ok = compileCode(clName.toString(), contents, diagnostics);

            String errorKey1 = "compiler.note.deprecated.filename";
            String errorKey2 = "compiler.note.deprecated.recompile";
            List<Diagnostic<? extends JavaFileObject>> diags = diagnostics.getDiagnostics();

            
            if (ok) {
                if (diags.size() == 0) {
                    error("Did not get any warnings for @Deprecated usage");
                } else {
                    for (Diagnostic<?> d : diags) {
                        if (d.getKind() == Diagnostic.Kind.NOTE) {
                            if (d.getCode().contains(errorKey1)
                                || d.getCode().contains(errorKey2)) {
                                System.out.println("TestCase =" + clName + " passed as expected");
                            } else {
                                error("TestCase =" + clName + " did not give correct warnings" +
                                    "Expected warning keys: " +
                                    "errorKey1 = " + errorKey1 +
                                    "errorKey2 = " + errorKey2 +
                                    "actualErrorKey = " + d.getCode(), contents);
                            }
                        } else {
                            error("Diagnostic Kind is incorrect, expected = " +
                                 Diagnostic.Kind.NOTE + "actual = " + d.getKind(), contents);
                        }
                    }
                }
            } else {
                error("TestCase =" + clName + " did not compile as expected", contents);
            }
        }

        System.out.println("Total number of tests run: " + testCtr);
        System.out.println("Total number of errors: " + errors);
        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    private String getContent(String className) {
        StringBuilder annoData = new StringBuilder();

        switch(className) {
        case "DeprecatedonBoth":
            annoData.append(Helper.ContentVars.DEPRECATED.getVal())
                    .append(Helper.ContentVars.CONTAINER.getVal())
                    .append(Helper.ContentVars.DEPRECATED.getVal())
                    .append(Helper.ContentVars.REPEATABLE.getVal())
                    .append(Helper.ContentVars.BASE.getVal());
            break;
        case "DeprecatedonBase":
            annoData.append(Helper.ContentVars.CONTAINER.getVal())
                    .append(Helper.ContentVars.DEPRECATED.getVal())
                    .append(Helper.ContentVars.REPEATABLE.getVal())
                    .append(Helper.ContentVars.BASE.getVal());
            break;
        case "DeprecatedonContainer":
            annoData.append(Helper.ContentVars.DEPRECATED.getVal())
                    .append(Helper.ContentVars.CONTAINER.getVal())
                    .append(Helper.ContentVars.REPEATABLE.getVal())
                    .append(Helper.ContentVars.BASE.getVal());
            break;
        }

        String contents = Helper.ContentVars.IMPORTCONTAINERSTMTS.getVal()
                          + Helper.ContentVars.IMPORTDEPRECATED.getVal()
                          + annoData
                          + Helper.ContentVars.REPEATABLEANNO.getVal()
                          + "\nclass "+ className + "{}";
        return contents;
    }

    private void error(String msg, String... contents) {
        System.out.println("error: " + msg);
        errors++;
        if (contents.length == 1) {
            System.out.println("Contents = " + contents[0]);
        }
    }
}
