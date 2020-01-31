



import java.io.*;
import javax.tools.*;

public class T6394683 {
    static final String testSrc = System.getProperty("test.src", ".");
    static final File a_java = new File(testSrc, "A.java");
    static final File a_class = new File("A.class");
    static final File b_class = new File("B.class");
    static final File b_java = new File("B.java");

    static abstract class TestFile extends File {
        TestFile(File file) {
            super(file.getPath());
        }

        abstract void create() throws IOException;
    }

    static class JavaTestFile extends TestFile {
        JavaTestFile(File file, String text) {
            super(file);
            this.text = text;
        }

        void create() throws IOException {
            BufferedWriter out = new BufferedWriter(new FileWriter(this));
            out.write(text);
            out.newLine();
            out.close();
        }

        private String text;
    }

    static TestFile good_java = new JavaTestFile(b_java, "class B { }");
    static TestFile bad_java  = new JavaTestFile(b_java, "class B");

    static TestFile good_class = new TestFile(b_class) {
            void create() throws IOException {
                JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
                int rc = javac.run(null, null, null,
                                   "-d", ".",
                                   new File(testSrc, "B.java").getPath());
                if (rc != 0)
                    throw new AssertionError("compilation failed, rc=" + rc + " creating B.class");
            }
        };

    static TestFile bad_class = new TestFile(b_class) {
            void create() throws IOException {
                FileOutputStream out = new FileOutputStream(b_class);
                out.close();
            }
        };


    public static void main(String ... args) throws Exception {
        boolean ok;

        ok  = test("-Xprefer:source", good_java, bad_class);
        ok &= test("-Xprefer:source", bad_class, good_java);
        ok &= test("-Xprefer:newer",  bad_java,  good_class);
        ok &= test("-Xprefer:newer",  bad_class, good_java);

        if (!ok)
            throw new AssertionError("test failed");
    }

    static boolean test(String opt, TestFile older, TestFile newer) throws Exception {

        
        a_class.delete();
        b_java.delete();
        b_class.delete();

        older.create();
        newer.create();
        if (!older.exists() || !newer.exists())
            throw new AssertionError("error creating files");

        int n = 0;
        while (newer.lastModified() <= older.lastModified()) {
            if (++n == 5)
                throw new Error("Cannot create files");
            Thread.sleep(1000);
            newer.create();
        }

        System.err.println("test:"
                           + "option:" + opt + ", "
                           + "older:" + older + "[" + older.length() + ":" + older.lastModified() + "], "
                           + "newer:" + newer + "[" + newer.length() + ":" + newer.lastModified() + "]");
        for (String s: new File(".").list())
            System.err.print(" " + s);
        System.err.println();

        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        int rc = javac.run(null, null, null,
                           "-d", ".",
                           "-classpath", ".",
                           "-sourcepath", ".",
                           opt,
                           a_java.getPath());
        if (rc != 0) {
            error("compilation failed, rc=" + rc + ", option: " + opt + ", older:" + older + ", newer" + newer);
            return false;
        }

        return true;
    }

    static void error(String msg) {
        System.err.println(msg);
    }
}
