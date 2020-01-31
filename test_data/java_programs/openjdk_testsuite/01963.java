



import java.io.*;
import java.nio.charset.*;
import java.nio.file.*;
import java.util.*;

public class TestWithXstdout {
    public static void main(String... args) throws Exception {
        File testSrc = new File(System.getProperty("test.src"));
        String testClasses = System.getProperty("test.classes", ".");
        String testClassPath = System.getProperty("test.class.path", testClasses);
        File stdout = new File("stdout.out");
        run_javac("-XDrawDiagnostics",
                "-XprintProcessorInfo",
                "-Werror",
                "-proc:only",
                "-processor",  "Test",
                "-Xstdout", stdout.getPath(),
                "-classpath", testClassPath,
                new File(testSrc, "Test.java").getPath());
        boolean ok = compare(stdout, new File(testSrc, "Test.out"));
        if (!ok)
            throw new Exception("differences found");
    }

    static void run_javac(String... args) throws IOException, InterruptedException {
        File javaHome = new File(System.getProperty("java.home"));
        if (javaHome.getName().equals("jre"))
            javaHome = javaHome.getParentFile();
        File javac = new File(new File(javaHome, "bin"), "javac");

        List<String> opts = new ArrayList<>();
        opts.add(javac.getPath());

        String toolOpts = System.getProperty("test.tool.vm.opts");
        if (toolOpts != null && !"".equals(toolOpts.trim())) {
            opts.addAll(Arrays.asList(toolOpts.trim().split("[\\s]+")));
        }
        opts.addAll(Arrays.asList(args));
        System.out.println("exec: " + opts);
        ProcessBuilder pb = new ProcessBuilder(opts);
        pb.redirectErrorStream();
        Process p = pb.start();
        try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()))) {
            String line;
            while ((line = r.readLine()) != null)
                System.out.println();
        }
        int rc = p.waitFor();
        if (rc != 0)
            System.out.println("javac exited, rc=" + rc);
    }

    static boolean compare(File a, File b) throws IOException {
        List<String> aLines = Files.readAllLines(a.toPath(), Charset.defaultCharset());
        List<String> bLines = Files.readAllLines(b.toPath(), Charset.defaultCharset());
        System.out.println(a + ": " + aLines.size() + " lines");
        System.out.println(b + ": " + bLines.size() + " lines");
        return aLines.equals(bLines);
    }
}
