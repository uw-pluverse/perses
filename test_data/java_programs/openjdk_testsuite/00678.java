



import java.io.*;


public class ArrayClone {
    public static void main(String[] args) {
        new ArrayClone().run();
    }

    public void run() {
        String[] args = { "-classpath", System.getProperty("test.classes", "."), "-v", "Test" };
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javap.Main.run(args, pw);
        if (rc != 0)
            throw new Error("javap failed; exit " + rc);

        String out = sw.toString();
        System.out.println(out);

        for (String line: out.split("(\\n|\\r\\n?)")) {
            String match = "[ \t]+[0-9]+:[ \t]+invokevirtual[ \t]+#[0-9]+[ \t]+// Method \"\\[Ljava/lang/String;\".clone:\\(\\)Ljava/lang/Object;";
            if (line.matches(match))
                return;
        }
        throw new Error("expected string not found in javap output");
    }
}

class Test {
    public static void main(String[] args) {
        args.clone();
    }
}
