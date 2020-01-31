

import java.io.*;
import java.util.*;


public class EarlyAssertWrapper {
    public static void main(String... args) throws Exception {
        EarlyAssertWrapper w = new EarlyAssertWrapper();
        w.run();
    }

    void run() throws Exception {
        List<String> cmd = new ArrayList<String>();
        File java_home = new File(System.getProperty("java.home"));
        if (java_home.getName().equals("jre"))
            java_home = java_home.getParentFile();
        cmd.add(new File(new File(java_home, "bin"), "java").getPath());

        
        
        cmd.add("-Xbootclasspath:" + System.getProperty("sun.boot.class.path"));

        
        cmd.add("-classpath");
        cmd.add(System.getProperty("java.class.path"));

        
        cmd.add("-da");
        cmd.add("-dsa");

        cmd.add("EarlyAssert");

        System.err.println("Running command: " + cmd);

        ProcessBuilder pb = new ProcessBuilder(cmd);
        pb.redirectErrorStream(true);
        Process p = pb.start();
        p.getOutputStream().close();

        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);

        String line;
        DataInputStream in = new DataInputStream(p.getInputStream());
        try {
        while ((line = in.readLine()) != null)
            pw.println(line);
        } finally {
            in.close();
        }
        pw.close();

        String out = sw.toString();
        int rc = p.waitFor();
        if (rc != 0 || out.length() > 0)
            throw new Error("failed: rc=" + rc + (out.length() > 0 ? ": " + out : ""));
    }
}
