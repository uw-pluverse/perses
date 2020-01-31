



import java.io.*;
import java.util.*;

public class TestPkgInfo {
    enum OptKind {
        NONE(null),
        ALWAYS("-Xpkginfo:always"),
        NONEMPTY("-Xpkginfo:nonempty"),
        LEGACY("-Xpkginfo:legacy");
        OptKind(String opt) { this.opt = opt; }
        final String opt;
    };

    public static void main(String... args) throws Exception {
        new TestPkgInfo().run(args);
    }
    public void run(String... args) throws Exception {
        testPositive();
        testNoExceptions();
    }
    public void testPositive(String... args) throws Exception {
        boolean[] booleanValues = { false, true };
        for (OptKind ok: OptKind.values()) {
            for (boolean sr: booleanValues) {
                for (boolean cr: booleanValues) {
                    for (boolean rr: booleanValues) {
                        try {
                            test(ok, sr, cr, rr);
                        } catch (Exception e) {
                            error("Exception: " + e);
                        }
                        if (errors > 0) throw new AssertionError();
                    }
                }
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    
    void testNoExceptions() throws Exception {
        count++;
        System.err.println("Test " + count + ": ALWAYS nofile");

        StringBuilder sb = new StringBuilder();
        sb.append("package test; class Hello{}");

        
        File tmpDir = new File("tmp.test" + count);
        File classesDir = new File(tmpDir, "classes");
        classesDir.mkdirs();
        File javafile = new File(new File(tmpDir, "src"), "Hello.java");
        writeFile(javafile, sb.toString());
        
        List<String> opts = new ArrayList<>();
        List<File> files = new ArrayList<>();

        opts.add("-d");
        opts.add(classesDir.getPath());
        opts.add("-Xpkginfo:always");
        files.add(javafile);

        compile(opts, files);
    }

    void test(OptKind ok, boolean sr, boolean cr, boolean rr) throws Exception {
        count++;
        System.err.println("Test " + count + ": ok:" + ok + " sr:" + sr + " cr:" + cr + " rr:" + rr);

        StringBuilder sb = new StringBuilder();

        
        if (sr) sb.append("@SR\n");
        if (cr) sb.append("@CR\n");
        if (rr) sb.append("@RR\n");
        sb.append("package p;\n");
        sb.append("\n");

        sb.append("import java.lang.annotation.*;\n");
        sb.append("@Retention(RetentionPolicy.SOURCE)  @interface SR { }\n");
        sb.append("@Retention(RetentionPolicy.CLASS)   @interface CR { }\n");
        sb.append("@Retention(RetentionPolicy.RUNTIME) @interface RR { }\n");

        
        File tmpDir = new File("tmp.test" + count);
        File classesDir = new File(tmpDir, "classes");
        classesDir.mkdirs();
        File pkginfo_java = new File(new File(tmpDir, "src"), "package-info.java");
        writeFile(pkginfo_java, sb.toString());

        
        List<String> opts = new ArrayList<>();
        List<File> files = new ArrayList<>();

        opts.add("-d");
        opts.add(classesDir.getPath());
        if (ok.opt != null)
            opts.add(ok.opt);
        
            files.add(pkginfo_java);

        compile(opts, files);

        File pkginfo_class = new File(new File(classesDir, "p"), "package-info.class");
        boolean exists = pkginfo_class.exists();

        boolean expected;
        switch (ok) {
            case ALWAYS:
                expected = true;
                break;

            case LEGACY:
            case NONE:
                expected = (sr || cr || rr ); 
                break;

            case NONEMPTY:
                expected = (cr || rr ); 
                break;

            default:
                throw new IllegalStateException();
        }

        if (exists && !expected)
            error("package-info.class found but not expected");
        if (!exists && expected)
            error("package-info.class expected but not found");
    }

    
    void compile(List<String> opts, List<File> files) throws Exception {
        System.err.println("javac: " + opts + " " + files);
        List<String> args = new ArrayList<>();
        args.addAll(opts);
        for (File f: files)
            args.add(f.getPath());
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.flush();
        if (sw.getBuffer().length() > 0)
            System.err.println(sw.toString());
        if (rc != 0)
            throw new Exception("compilation failed: rc=" + rc);
    }

    
    void writeFile(File f, String body) throws Exception {
        if (f.getParentFile() != null)
            f.getParentFile().mkdirs();
        Writer out = new FileWriter(f);
        try {
            out.write(body);
        } finally {
            out.close();
        }
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    
    int count;

    
    int errors;
}
