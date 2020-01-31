



import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;

public class T6759996 {
    public static void main(String[] args) throws Exception {
        new T6759996().run();
    }

    void run() throws IOException, InterruptedException {
        String PS = File.pathSeparator;
        write(new File("A.java"), "class A { }");
        write(new File("B.java"), "class B extends A { }");
        
        
        javac("-verbose", "-sourcepath", "" + PS + ".", "B.java");
    }

    void javac(String... args) throws IOException, InterruptedException {
        StringWriter sw = new StringWriter();
        PrintWriter out = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, out);
        System.out.println(sw.toString());
        if (rc != 0)
            throw new Error("javac failed: rc=" + rc);

    }

    void write(File to, String body) throws IOException {
        System.err.println("write " + to);
        File toDir = to.getParentFile();
        if (toDir != null) {
            boolean ok = toDir.mkdirs();
            if (!ok) {
                throw new Error("could not create directory " + toDir);
            }
        }
        Writer out = new FileWriter(to);
        try {
            out.write(body);
            if (!body.endsWith("\n"))
                out.write("\n");
        } finally {
            out.close();
        }
    }
}
