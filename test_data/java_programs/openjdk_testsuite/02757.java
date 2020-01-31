




import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URL;

public class VersionOpt {
    public static void main(String... args) throws Exception {
        new VersionOpt().run();
    }

    void run() throws Exception {
        
        
        
        
        
        
        Class<?> javacClass = com.sun.tools.javac.Main.class;
        URL javacURL = getClass().getClassLoader().getResource(javacClass.getName().replace(".", "/") + ".class");
        if (!javacURL.getProtocol().equals("jar") || !javacURL.getFile().contains("!")) {
            System.err.println("javac not found in tools.jar: " + javacURL);
            System.err.println("rest of test skipped");
            return;
        }
        String javacHome = javacURL.getFile().substring(0, javacURL.getFile().indexOf("!"));

        File javaHome = new File(System.getProperty("java.home"));
        if (javaHome.getName().equals("jre"))
            javaHome = javaHome.getParentFile();
        File toolsJar = new File(new File(javaHome, "lib"), "tools.jar");

        if (!javacHome.equalsIgnoreCase(toolsJar.toURI().toString())) {
            System.err.println("javac not found in tools.jar: " + javacHome);
            System.err.println("rest of test skipped");
            return;
        }

        System.out.println("javac found in " + toolsJar);

        String javaVersion = System.getProperty("java.version");
        String javaRuntimeVersion = System.getProperty("java.runtime.version");
        System.out.println("java.version: " + javaVersion);
        System.out.println("java.runtime.version: " + javaRuntimeVersion);

        StringWriter sw = new StringWriter();
        com.sun.tools.javac.Main.compile(new String[] { "-version" }, new PrintWriter(sw));
        String javacVersion = sw.toString().trim();

        sw = new StringWriter();
        com.sun.tools.javac.Main.compile(new String[] { "-fullversion" }, new PrintWriter(sw));
        String javacFullVersion = sw.toString().trim();
        System.out.println("javac -version: " + javacVersion);
        System.out.println("javac -fullversion: " + javacFullVersion);

        checkEqual("javac -version", javacVersion, "javac " + javaVersion);
        checkEqual("javac -fullversion", javacFullVersion, "javac full version \"" + javaRuntimeVersion + "\"");

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void checkEqual(String kind, String found, String expect) {
        if (!found.equals(expect)) {
            System.err.println("error: unexpected value for " + kind);
            System.err.println("expect: >>" + expect + "<<");
            System.err.println(" found: >>" + found + "<<");
            errors++;
        }
    }

    int errors;
}
