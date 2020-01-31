



import java.util.HashMap;
import java.util.Map;

import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;
import javax.tools.Diagnostic;



public class RetentionAnnoCombo extends Helper {
    static int errors = 0;
    static boolean exitMode = false;
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

    public static void main(String args[]) throws Exception {
        new RetentionAnnoCombo().runTest();
    }

    public void runTest() throws Exception {

        
        int[][] retention = { {1, 0, 0, 0},
                              {1, 1, 1, 0},
                              {1, 1, 1, 0},
                              {1, 1, 1, 1} };

        Map<Integer, String> retMap = setRetentionValMatrix();
        String contents = "";
        boolean result = false;
        int testCtr = 0;
        for (int i = 0; i < 4 ; i ++) {
            for (int j = 0; j < 4; j++ ) {
                testCtr++;
                String className = "RetentionTest_"+i+"_"+j;
                contents = getContent(className, retMap, i, j);
                if (retention[i][j] == 1) {
                    
                    result = getCompileResult(contents,className, true);
                    if (!result) {
                        error("FAIL: " +  className + " did not compile as expected!", contents);
                    }
                } else {
                    result = getCompileResult(contents,className, false);
                    if (!result) {
                        error("FAIL: " +  className + " compiled unexpectedly!", contents);
                    }
                }
                if (result) {
                    System.out.println("Test passed for className = " + className);
                }
            }
        }

        System.out.println("Total number of tests run: " + testCtr);
        System.out.println("Total number of errors: " + errors);

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    private boolean getCompileResult(String contents, String className,
            boolean shouldCompile) throws Exception{

        DiagnosticCollector<JavaFileObject> diagnostics =
                new DiagnosticCollector<JavaFileObject>();
        boolean ok = compileCode(className, contents, diagnostics);

        String expectedErrKey = "compiler.err.invalid.repeatable" +
                                        ".annotation.retention";
        if (!shouldCompile && !ok) {
            for (Diagnostic<?> d : diagnostics.getDiagnostics()) {
                if (!((d.getKind() == Diagnostic.Kind.ERROR) &&
                    d.getCode().contains(expectedErrKey))) {
                    error("FAIL: Incorrect error given, expected = "
                            + expectedErrKey + ", Actual = " + d.getCode()
                            + " for className = " + className, contents);
                }
            }
        }

        return (shouldCompile  == ok);
    }

    private Map<Integer,String> setRetentionValMatrix() {
        HashMap<Integer,String> hm = new HashMap<>();
        hm.put(0,"SOURCE");
        hm.put(1,"DEFAULT");
        hm.put(2,"CLASS");
        hm.put(3,"RUNTIME");
        return hm;
    }

    private String getContent(String className, Map<Integer, String> retMap,
            int i, int j) {

        String retContainerVal = retMap.get(i).toString();
        String retBaseVal = retMap.get(j).toString();
        String replacedRetBaseVal = "", replacedRetCAVal = "";
        String retention = Helper.ContentVars.RETENTION.getVal();

        
        if (retContainerVal.equalsIgnoreCase("DEFAULT")
                && retBaseVal.equalsIgnoreCase("DEFAULT")) {
            replacedRetBaseVal = "";
            replacedRetCAVal = "";
        
        } else if (retContainerVal.equalsIgnoreCase("DEFAULT")) {
            replacedRetBaseVal = retention.replace("#VAL", retBaseVal);
            replacedRetCAVal = "";
        
        } else if (retBaseVal.equalsIgnoreCase("DEFAULT")) {
            replacedRetBaseVal = "";
            replacedRetCAVal = retention.replace("#VAL", retContainerVal);
        
        } else {
            replacedRetBaseVal = retention.replace("#VAL", retBaseVal);
            replacedRetCAVal = retention.replace("#VAL", retContainerVal);
        }

        StringBuilder annoData = new StringBuilder();
        annoData.append(Helper.ContentVars.IMPORTCONTAINERSTMTS.getVal())
                .append(Helper.ContentVars.IMPORTRETENTION.getVal())
                .append(replacedRetCAVal)
                .append(Helper.ContentVars.CONTAINER.getVal())
                .append(Helper.ContentVars.REPEATABLE.getVal())
                .append(replacedRetBaseVal)
                .append(Helper.ContentVars.BASE.getVal());

        String contents = annoData
                          + Helper.ContentVars.REPEATABLEANNO.getVal()
                          + "\nclass "+ className + "{}";
        return contents;
    }

    private void error(String msg,String... contents) throws Exception {
        System.out.println("error: " + msg);
        errors++;
        if (contents.length == 1) {
            System.out.println("Contents = " + contents[0]);
        }
        
        if (exitMode) throw new Exception();
    }
}

