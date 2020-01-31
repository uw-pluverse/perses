



import java.io.*;
import java.util.*;

public class T6917288 {
    
    enum Kind { NONE, FALSE, TRUE, ALWAYS };

    public static void main(String... args) throws Exception {
        new T6917288().run();
    }

    void run() throws Exception {
        for (Kind k: Kind.values()) {
            test(k);
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    
    void test(Kind k) throws Exception {
        System.err.println("Test " + (++count) + ": " + k);
        File testDir = new File("test" + count);
        File srcDir = new File(testDir, "src");
        srcDir.mkdirs();
        File classesDir = new File(testDir, "classes");
        classesDir.mkdirs();

        List<String> opts = new ArrayList<String>();
        opts.add("-d");
        opts.add(classesDir.getPath());

        File f = writeFile(srcDir, k);
        int rc = compile(opts, f);
        if (rc != 0) {
            error("compilation failed: rc=" + rc);
            return;
        }

        check(classesDir, "Test.class", "Test$Inner.class", "Test$1.class");
    }

    
    int compile(List<String> opts, File... files) {
        List<String> args = new ArrayList<String>();
        args.addAll(opts);
        for (File f: files)
            args.add(f.getPath());
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.close();
        String out = sw.toString();
        if (out.length() > 0)
            System.err.println(out);
        return rc;
    }

    
    void check(File dir, String... paths) {
        Set<String> found = new TreeSet<String>(Arrays.asList(dir.list()));
        Set<String> expect = new TreeSet<String>(Arrays.asList(paths));
        if (found.equals(expect))
            return;
        for (String f: found) {
            if (!expect.contains(f))
                error("Unexpected file found: " + f);
        }
        for (String e: expect) {
            if (!found.contains(e))
                error("Expected file not found: " + e);
        }
    }

    
    File writeFile(File dir, Kind k) throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append("public class Test {\n");
        sb.append("    private Inner inner;\n");

        
        if (k != Kind.NONE) {
            sb.append("    private void m() {\n");
            sb.append("        ");
            switch (k) {
                case FALSE: case TRUE:
                    sb.append("if (" + k.toString().toLowerCase() + ") ");
            }
            sb.append("new Runnable() { public void run() { } };\n");
            sb.append("    }\n");
        }

        sb.append("    private void init() {\n");
        sb.append("        inner = new Inner();\n");
        sb.append("    }\n");
        sb.append("\n");
        sb.append("    private static class Inner {\n");
        sb.append("        private Inner() {\n");
        sb.append("        }\n");
        sb.append("    }\n");
        sb.append("}\n");

        File f = new File(dir, "Test.java");
        FileWriter w = new FileWriter(f);
        w.write(sb.toString());
        w.close();
        return f;
    }

    
    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int count;
    int errors;
}
