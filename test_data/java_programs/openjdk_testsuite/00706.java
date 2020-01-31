    

    

    import java.io.*;
    import java.util.*;
    import javax.tools.*;

    import com.sun.source.util.JavacTask;
    import com.sun.tools.javac.api.JavacTool;

    public class T6430241 {
        public static void main(String... args) throws Exception {
            new T6430241().run();
        }

        void run() throws Exception {
            setup();
            testCommandLine();
            testSimpleAPI();
            testTaskAPI();

            if (errors > 0)
                throw new Exception(errors + " errors found");
        }

        void setup() throws Exception {
            classesDir = new File("classes");
            classesDir.mkdirs();

            emptyDir = new File("empty");
            emptyDir.mkdirs();

            bootClassPath = System.getProperty("sun.boot.class.path");

            File srcDir = new File("src");
            String test = "import sun.misc.Unsafe; class Test { }";
            testFile = writeFile(srcDir, "Test.java", test);
        }

        

        void testCommandLine() throws Exception {
            testCommandLine(true);
            testCommandLine(true,  "-Xbootclasspath/p:" + emptyDir);
            testCommandLine(false, "-Xbootclasspath:" + bootClassPath);
            testCommandLine(true,  "-Xbootclasspath/a:" + emptyDir);
            testCommandLine(false, "-XDignore.symbol.file");
            System.err.println();
        }

        void testCommandLine(boolean expectWarnings, String... opts) throws Exception {
            System.err.println("test command line: " + Arrays.asList(opts));

            String[] args = initArgs(opts);

            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            int rc = com.sun.tools.javac.Main.compile(args, pw);
            String out = showOutput(sw.toString());

            checkCompilationOK(rc);
            checkOutput(out, expectWarnings);
        }

        

        void testSimpleAPI() {
            testSimpleAPI(true);
            testSimpleAPI(true,  "-Xbootclasspath/p:" + emptyDir);
            testSimpleAPI(false, "-Xbootclasspath:" + bootClassPath);
            testSimpleAPI(true,  "-Xbootclasspath/a:" + emptyDir);
            testSimpleAPI(false, "-XDignore.symbol.file");
            System.err.println();
        }

        void testSimpleAPI(boolean expectWarnings, String... opts) {
            System.err.println("test simple API: " + Arrays.asList(opts));

            String[] args = initArgs(opts);

            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            PrintStream ps = new PrintStream(baos);

            JavacTool tool = JavacTool.create();
            int rc = tool.run(null, null, ps, args);

            String out = showOutput(baos.toString());

            checkCompilationOK(rc);
            checkOutput(out, expectWarnings);
        }

        

        void testTaskAPI() throws Exception {
            List<File> bcp = new ArrayList<File>();
            for (String f: bootClassPath.split(File.pathSeparator)) {
                if (!f.isEmpty())
                    bcp.add(new File(f));
            }

            testTaskAPI(true, null);
            testTaskAPI(false, bcp);
            System.err.println();
        }

        void testTaskAPI(boolean expectWarnings, Iterable<? extends File> pcp) throws Exception {
            System.err.println("test task API: " + pcp);

            JavacTool tool = JavacTool.create();
            StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);

            if (pcp != null)
                fm.setLocation(StandardLocation.PLATFORM_CLASS_PATH, pcp);

            Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(testFile);

            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            JavacTask task = tool.getTask(pw, fm, null, null, null, files);
            boolean ok = task.call();
            String out = showOutput(sw.toString());

            checkCompilationOK(ok);
            checkOutput(out, expectWarnings);
        }

        

        
        File writeFile(File dir, String path, String content) throws IOException {
            File f = new File(dir, path);
            f.getParentFile().mkdirs();
            FileWriter out = new FileWriter(f);
            try {
                out.write(content);
            } finally {
                out.close();
            }
            return f;
        }

        
        String[] initArgs(String[] opts) {
            List<String> args = new ArrayList<String>();
            args.addAll(Arrays.asList(opts));
            args.add("-d");
            args.add(classesDir.getPath());
            args.add(testFile.getPath());
            return args.toArray(new String[args.size()]);
        }

        
        String showOutput(String out) {
            if (!out.isEmpty())
                System.err.println(out);
            return out;
        }

        
        void checkCompilationOK(boolean ok) {
            if (!ok)
                error("compilation failed");
        }

        
        void checkCompilationOK(int rc) {
            if (rc != 0)
                error("compilation failed, rc: " + rc);
        }

        
        void checkOutput(String out, boolean expectWarnings) {
            boolean foundWarnings = out.contains("warning");
            if (foundWarnings) {
                if (!expectWarnings)
                    error("unexpected warnings found");
            } else {
                if (expectWarnings)
                    error("expected warnings not found");
            }
        }

        
        void error(String msg) {
            System.err.println("error: " + msg);
            errors++;
        }

        String bootClassPath;
        File classesDir;
        File emptyDir;
        File testFile;
        int errors;
    }
