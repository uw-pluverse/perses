



import java.io.*;
import java.nio.*;
import java.util.*;
import java.util.regex.*;

public class ClassVersionChecker {

    int errors;
    String[] jdk = {"","1.2","1.3","1.4","1.5","1.6","1.7","1.8"};
    File javaFile = null;

    public static void main(String[] args) throws Throwable {
        new ClassVersionChecker().run();
    }

    void run() throws Exception {
        writeTestFile();
        

        
        int[][] ver =
                {{52, -1, -1, -1, -1, -1, -1, -1},
                 {48, 46, 47, 48, 49, 50, 51, 52},
                 {48, 46, 47, 48, 49, 50, 51, 52},
                 {48, -1, -1, 48, 49, 50, 51, 52},
                 {52, -1, -1, -1, 49, 50, 51, 52},
                 {52, -1, -1, -1, -1, 50, 51, 52},
                 {52, -1, -1, -1, -1, -1, 51, 52},
                 {52, -1, -1, -1, -1, -1, -1, 52}};

        
        for (int i = 0; i< ver.length; i++) {
            for (int j = 0 ; j< ver[i].length; j++) {
                if(ver[i][j] != -1) {
                    logMsg("Index values for i = " + i + " j = " + j);
                    logMsg("Running for src = " + jdk[i] + " target = "+jdk[j] +" expected = " + ver[i][j]);
                    test(i,j, ver[i][j]);
                }
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void test (int i, int j, int expected) {
        File classFile = compileTestFile(i, j, javaFile);
        short majorVer = getMajorVersion(classFile);
        checkVersion(majorVer, expected);
    }

    void writeTestFile() throws IOException {
        javaFile = new File("Test.java");
        try(PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(javaFile)));) {
            out.println("class Test { ");
            out.println("  public void foo() { }");
            out.println("}");
        } catch (IOException ioe) {
            error("IOException while creating Test.java" + ioe);
        }
    }

    File compileTestFile(int i , int j, File f) {
        int rc = -1;
        
        if (i == 0 && j == 0 ) {
            rc = compile("-g", f.getPath());
        } else if( j == 0 ) {  
            rc = compile("-source", jdk[i], "-g", f.getPath());
        } else {
            rc = compile("-source", jdk[i], "-target", jdk[j], "-g", f.getPath());
        }
        if (rc != 0)
            throw new Error("compilation failed. rc=" + rc);
        String path = f.getPath();
        return new File(path.substring(0, path.length() - 5) + ".class");
    }

    int compile(String... args) {
        return com.sun.tools.javac.Main.compile(args);
    }

    void logMsg (String str) {
        System.out.println(str);
    }

    short getMajorVersion(File f) {
        List<String> args = new ArrayList<String>();
        short majorVer = 0;
        try(DataInputStream in = new DataInputStream(new BufferedInputStream(new FileInputStream(f)));) {
            in.readInt();
            in.readShort();
            majorVer = in.readShort();
            System.out.println("major version:" +  majorVer);
        } catch (IOException e) {
            error("IOException while reading Test.class" + e);
        }
        return majorVer;
    }

    void checkVersion(short majorVer, int expected) {
        if (majorVer != expected ) {
            error("versions did not match, Expected: " + expected + "Got: " + majorVer);
        }
    }

    void error(String msg) {
       System.out.println("error: " + msg);
       errors++;
    }
}
