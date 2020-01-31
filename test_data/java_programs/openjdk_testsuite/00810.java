




import java.io.*;
import java.util.*;

public class GraphicalInstallerTest {
    public static void main(String... args) throws Exception {
        new GraphicalInstallerTest().run();
    }

    void run() throws Exception {
        File testSrc = new File(System.getProperty("test.src"));
        File classes = new File("classes");
        classes.mkdirs();
        List<String> opts = Arrays.asList("-d", classes.getPath());
        int rc = compile(opts, new File(testSrc, "GraphicalInstaller.java"));
        if (rc != 0) {
            error("compilation failed: rc=" + rc);
            return;
        }

        check(classes,
            "GraphicalInstaller$1.class",
            "GraphicalInstaller$1X$1.class",
            "GraphicalInstaller$1X.class",
            "GraphicalInstaller$BackgroundInstaller.class",
            "GraphicalInstaller.class");

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
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

    
    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int errors;
}
