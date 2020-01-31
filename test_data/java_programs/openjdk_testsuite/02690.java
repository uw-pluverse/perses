




import java.io.*;
import java.util.*;






public class Test {
    enum ShouldStopPolicy {
        BLANK(false, null, "attr"),
        PROCESS(true, null, "attr"),
        ATTR(true, "attr", "flow"),
        FLOW(true, "flow", "desugar"),
        TRANSTYPES(true, "desugar", "generate"),
        LOWER(true, "desugar", "generate"),
        GENERATE(true, "generate", null);
        ShouldStopPolicy(boolean needOption, String expect, String dontExpect) {
            this.needOption = needOption;
            this.expect = expect;
            this.dontExpect = dontExpect;
        }
        boolean needOption;
        String expect;
        String dontExpect;
    }

    enum CompilePolicy {
        BYFILE,
        BYTODO
    }

    public static void main(String... args) throws Exception {
        new Test().run();
    }

    public void run() throws Exception {
        for (CompilePolicy cp: CompilePolicy.values()) {
            for (ShouldStopPolicy ssp: ShouldStopPolicy.values()) {
                test(cp, ssp);
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    public void test(CompilePolicy cp, ShouldStopPolicy ssp) {
        System.err.println();
        System.err.println("test " + cp + " " + ssp);
        List<String> args = new ArrayList<String>();
        args.add("-XDverboseCompilePolicy");
        args.add("-XDcompilePolicy=" + cp.toString().toLowerCase());
        args.add("-d");
        args.add(".");
        if (ssp.needOption)
            args.add("-XDshouldStopPolicy=" + ssp);
        args.add(new File(System.getProperty("test.src", "."), "A.java").getPath());

        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        System.err.println("compile " + args);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        if (rc == 0)
            throw new Error("compilation succeeded unexpectedly");
        

        
        
        
        
        if (cp == CompilePolicy.BYTODO && ssp == ShouldStopPolicy.PROCESS)
            ssp = ShouldStopPolicy.ATTR;

        boolean foundExpected = (ssp.expect == null);
        String[] lines = sw.toString().split("\n");
        for (String line: lines) {
            if (ssp.expect != null && line.startsWith("[" + ssp.expect))
                foundExpected = true;
            if (ssp.dontExpect != null && line.startsWith("[" + ssp.dontExpect)) {
                error("Unexpected output: " + ssp.dontExpect + "\n" + sw);
                return;
            }
        }

        if (!foundExpected)
            error("Expected output not found: " + ssp.expect + "\n" + sw);
    }

    void error(String message) {
        System.err.println(message);
        errors++;
    }

    int errors;
}
