



import java.io.*;

public class TestBadProcessor {
    public static void main(String... args) throws Exception {
        new TestBadProcessor().run();
    }

    public static final String badAnnoProcSrc =
        "import java.util.*;\n" +
        "import javax.annotation.processing.*;\n" +
        "import javax.lang.model.element.*;\n" +

        "public class AnnoProc extends AbstractProcessor {\n" +
        "    public AnnoProc() {\n" +
        "        throw new Error();\n" +
        "    }\n" +

        "    public boolean process(Set<? extends TypeElement> elems, \n" +
        "                        RoundEnvironment rEnv) {\n" +
        "        return false;\n" +
        "    }\n" +
        "}\n";

    public void run() throws Exception {
        
        File srcDir = new File("src");
        File classesDir = new File("classes");
        classesDir.mkdirs();
        File srcFile = writeFile(srcDir, "AnnoProc.java", badAnnoProcSrc);
        compile("-d", classesDir.getPath(), srcFile.getPath());
        writeFile(classesDir, "META-INF/services/javax.annotation.processing.Processor", "AnnoProc");

        
        int rc;
        StringWriter sw = new StringWriter();
        try (PrintWriter pw = new PrintWriter(sw)) {
            String[] args = { "-processorpath", classesDir.getPath(), srcFile.getPath() };
            rc = com.sun.tools.javac.Main.compile(args, pw);
        }

        
        String out = sw.toString();
        System.err.println(out);
        String expect = "error: Bad service configuration file, " +
                "or exception thrown while constructing Processor object: " +
                "javax.annotation.processing.Processor: " +
                "Provider AnnoProc could not be instantiated: java.lang.Error";
        if (!out.trim().equals(expect)) {
            System.err.println("expected: " + expect);
            error("output not as expected");
        }

        if (rc == 0) {
            error("unexpected exit code: " + rc + "; expected: not zero");
        }

        
        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void compile(String... args) throws Exception {
        int rc;
        StringWriter sw = new StringWriter();
        try (PrintWriter pw = new PrintWriter(sw)) {
            rc = com.sun.tools.javac.Main.compile(args, pw);
        }
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (rc != 0)
            throw new Exception("compilation failed");
    }

    File writeFile(File dir, String path, String body) throws IOException {
        File f = new File(dir, path);
        f.getParentFile().mkdirs();
        try (FileWriter out = new FileWriter(f)) {
            out.write(body);
        }
        return f;
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
