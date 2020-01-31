

import java.io.*;


public class T6534287 {
    public static void main(String... args) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        com.sun.tools.javac.Main.compile(new String[] { "" }, pw);
        pw.close();
        sw.close();
        String output = sw.toString();
        System.err.println("output from javac: ");
        System.err.println(output);
        if (output.indexOf("Exception") != -1)
            throw new Exception("exception in output from javac");
    }
}
