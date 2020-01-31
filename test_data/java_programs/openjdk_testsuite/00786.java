



import java.io.*;
import java.util.*;
import javax.tools.*;

public class T6731573 extends ToolTester {

    enum DiagnosticType {
        BASIC(null) {
            boolean shouldDisplaySource(SourceLine sourceLine) {
                return sourceLine != SourceLine.DISABLED;
            }
        },
        RAW("-XDrawDiagnostics") {
            boolean shouldDisplaySource(SourceLine sourceLine) {
                return sourceLine == SourceLine.ENABLED;
            }
        };

        String optValue;

        DiagnosticType(String optValue) {
            this.optValue = optValue;
        }

        abstract boolean shouldDisplaySource(SourceLine sourceLine);
    }

    enum SourceLine {
        STANDARD(null),
        ENABLED("-XDshowSource=true"),
        DISABLED("-XDshowSource=false");

        String optValue;

        SourceLine(String optValue) {
            this.optValue = optValue;
        }
    }

    void checkErrorLine(String output, boolean expected, List<String> options) {
        System.err.println("\noptions = "+options);
        System.err.println(output);
        boolean errLinePresent = output.contains("^");
        if (errLinePresent != expected) {
            throw new AssertionError("Error in diagnostic: error line" +
                    (expected ? "" : " not") + " expected but" +
                    (errLinePresent ? "" : " not") + " found");
        }
    }

    void exec(DiagnosticType diagType, SourceLine sourceLine) {
        final Iterable<? extends JavaFileObject> compilationUnits =
            fm.getJavaFileObjects(new File(test_src, "Erroneous.java"));
        StringWriter pw = new StringWriter();
        ArrayList<String> options = new ArrayList<String>();
        if (diagType.optValue != null)
            options.add(diagType.optValue);
        if (sourceLine.optValue != null)
            options.add(sourceLine.optValue);
        task = tool.getTask(pw, fm, null, options, null, compilationUnits);
        task.call();
        checkErrorLine(pw.toString(),
                diagType.shouldDisplaySource(sourceLine),
                options);
    }

    void test() {
        for (DiagnosticType dt : DiagnosticType.values()) {
            for (SourceLine sl : SourceLine.values()) {
                exec(dt, sl);
            }
        }
    }

    public static void main(String... args) throws Exception {
        new T6731573().test();
    }
}
