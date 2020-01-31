





































import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test1b
{
    public static void main(String... args) throws Exception {
        new Test1b().run(args);
    }

    void run(String... args) throws Exception {
        File testSrcDir = new File(System.getProperty("test.src"));
        File tmpClassDir = new File(".");
        List<String> l = new ArrayList<String>();
        l.add("-d");
        l.add(tmpClassDir.getPath());
        for (String a: args) {
            if (a.endsWith(".java"))
                l.add(new File(testSrcDir, a).getPath());
            else
                l.add(a);
        }

        StringWriter sw = new StringWriter();
        int rc = com.sun.tools.javac.Main.compile(l.toArray(new String[l.size()]), new PrintWriter(sw));
        System.err.println(sw);

        Pattern p = Pattern.compile("([A-Z]+).*");
        for (String name: tmpClassDir.list()) {
            if (name.endsWith(".class")) {
                Matcher m = p.matcher(name);
                if (m.matches()) {
                    found(m.group(1), name);
                }
            }
        }

        
        
        check("A", 3);
        check("B", 3);
        check("C", 3);
        check("D", 3);

        if (errors > 0)
            throw new Exception(errors + " errors");
    }

    void check(String prefix, int expect) {
        List<String> names = map.get(prefix);
        int found = (names == null ? 0 : names.size());
        if (found == 0 || found == expect) {
            System.err.println("Found " + found + " files for " + prefix + ": OK");
            return;
        }
        error("Found " + found + " files for " + prefix + ": expected 0 or " + expect + " " + names);
    }

    void found(String prefix, String name) {
        List<String> names = map.get(prefix);
        if (names == null) {
            names = new ArrayList<String>();
            map.put(prefix, names);
        }
        names.add(name);
    }

    void error(String message) {
        System.err.println(message);
        errors++;
    }

    Map<String,List<String>> map = new HashMap<String,List<String>>();
    int errors;
}
