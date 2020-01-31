



import java.io.*;
import javax.tools.*;



public class ToolProviderTest2 {
    public static void main(String... args) throws Exception {
        if (args.length > 0) {
            System.err.println(ToolProvider.getSystemJavaCompiler());
            return;
        }

        new ToolProviderTest2().run();
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
            ToolProviderTest2.class.getName(),
            "javax.tools.ToolProvider"
        };

        ProcessBuilder pb = new ProcessBuilder(cmd).redirectErrorStream(true);
        Process p = pb.start();
        BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String line;
        boolean found = false;
        while ((line = r.readLine()) != null) {
            System.err.println(line);
            if (line.contains("com.sun.tools.javac."))
                found = true;
        }
        int rc = p.waitFor();
        if (rc != 0)
            error("Unexpected exit code: " + rc);

        if (!found)
            System.err.println("expected class name not found");

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int errors;
}
