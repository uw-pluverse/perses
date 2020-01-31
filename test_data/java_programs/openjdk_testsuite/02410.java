



import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;


public class DocumentedAnnoCombo extends Helper {
    static int errors = 0;

    enum TestCases {
        DocumentedonBothAnno(true),
        DocumentedonContainer(true);

        TestCases(boolean compile) {
            this.compile = compile;
        }

        boolean compile;
        boolean shouldCompile() {
            return compile;
        }
    }

    public static void main(String[] args) throws Exception {
        new DocumentedAnnoCombo().runTest();
    }

    public void runTest() throws Exception {
        boolean ok = false;
        int testCtr = 0;

        
        for (TestCases className : TestCases.values()) {
            testCtr++;
            String contents = getContent(className.toString());

            
            DiagnosticCollector<JavaFileObject> diagnostics =
                    new DiagnosticCollector<JavaFileObject>();
            ok = compileCode(className.toString(), contents, diagnostics);
            if (!ok) {
                error("Class="+ className +" did not compile as expected", contents);
            } else {
                System.out.println("Test passed for className: " + className);
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
            case "DocumentedonBothAnno":
                annoData.append(Helper.ContentVars.DOCUMENTED.getVal())
                .append(Helper.ContentVars.CONTAINER.getVal())
                .append(Helper.ContentVars.DOCUMENTED.getVal())
                .append(Helper.ContentVars.REPEATABLE.getVal())
                .append(Helper.ContentVars.BASE.getVal());
            break;
            case "DocumentedonContainer":
                annoData.append(Helper.ContentVars.DOCUMENTED.getVal())
                .append(Helper.ContentVars.CONTAINER.getVal())
                .append(Helper.ContentVars.REPEATABLE.getVal())
                .append(Helper.ContentVars.BASE.getVal());
            break;
        }

        String contents = Helper.ContentVars.IMPORTCONTAINERSTMTS.getVal()
                          + Helper.ContentVars.IMPORTDOCUMENTED.getVal()
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

