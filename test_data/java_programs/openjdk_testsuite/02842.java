



import java.io.*;
import java.util.*;

public class T6668802
{
    public static void main(String[] args) throws Exception {
        new T6668802().run();
    }

    void run() throws Exception {
        String test = "public class Test {";
        File f = writeTestFile("Test.java", test);
        String[] out = compileBadFile(f);
        for (String line: out)
            System.err.println(">>>" + line + "<<<");
        if (!out[1].equals(test)) {
            show("expected", test);
            show("  actual", out[1]);
            throw new Error("test failed");
        }
    }

    File writeTestFile(String path, String contents) throws IOException {
        File f = new File(path);
        FileWriter out = new FileWriter(f);
        out.write(contents);
        out.close();
        return f;
    }

    String[] compileBadFile(File file) throws IOException {
        List<String> options = new ArrayList<String>();
        options.add(file.getPath());
        System.err.println("compile: " + options);
        String[] opts = options.toArray(new String[options.size()]);
        StringWriter sw = new StringWriter();
        PrintWriter out = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(opts, out);
        if (rc == 0)
            throw new Error("compilation succeeded unexpectedly");
        out.close();
        return sw.toString().split("[\n\r]+");
    }

    void show(String prefix, String text) {
        System.err.println(prefix + ": (" + text.length() + ") " + text);
    }
}
