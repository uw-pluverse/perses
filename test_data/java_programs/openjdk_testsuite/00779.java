



import java.io.*;



public class ToolProviderTest1 {
    public static void main(String... args) throws Exception {
        if (args.length > 0) {
            System.err.println(Class.forName(args[0], true, null));
            return;
        }

        new ToolProviderTest1().run();
    }

    void run() throws Exception {
        File javaHome = new File(System.getProperty("java.home"));
        if (javaHome.getName().equals("jre"))
            javaHome = javaHome.getParentFile();
        File javaExe = new File(new File(javaHome, "bin"), "java");
        String classpath = System.getProperty("java.class.path");

        String[] cmd = {
            javaExe.getPath(),
            "-verbose:class",
            "-classpath", classpath,
            ToolProviderTest1.class.getName(),
            "javax.tools.ToolProvider"
        };

        ProcessBuilder pb = new ProcessBuilder(cmd).redirectErrorStream(true);
        Process p = pb.start();
        BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String line;
        while ((line = r.readLine()) != null) {
            System.err.println(line);
            if (line.contains("com.sun.tools.javac."))
                error(">>> " + line);
        }
        int rc = p.waitFor();
        if (rc != 0)
            error("Unexpected exit code: " + rc);

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int errors;
}
