



import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;

import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;

public class NativeHeaderTest {
    public static void main(String... args) throws Exception {
        new NativeHeaderTest().run();
    }

    
    enum RunKind {
        
        CMD,
        
        API
    };

    
    enum GenKind {
        
        SIMPLE,
        
        FULL
    };

    

    @Test
    void simpleTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C { native void m(); }"));

        Set<String> expect = createSet("C.h");

        test(rk, gk, files, expect);
    }

    @Test
    void nestedClassTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C { static class Inner { native void m(); } }"));

        Set<String> expect = createSet("C_Inner.h");
        if (gk == GenKind.FULL) expect.add("C.h");

        test(rk, gk, files, expect);
    }

    @Test
    void localClassTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C { native void m(); void m2() { class Local { } } }"));

        Set<String> expect = createSet("C.h");

        test(rk, gk, files, expect);
    }

    @Test
    void syntheticClassTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C {\n"
                + "    private C() { }\n"
                + "    class Inner extends C { native void m(); }\n"
                + "}"));

        Set<String> expect = createSet("C_Inner.h");
        if (gk == GenKind.FULL) expect.add("C.h");

        test(rk, gk, files, expect);

        
        checkEqual("generatedClasses",
                createSet("C.class", "C$1.class", "C$Inner.class"),
                createSet(classesDir.list()));
    }

    @Test
    void annoTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C { @java.lang.annotation.Native public static final int i = 1907; }"));

        Set<String> expect = createSet("C.h");

        test(rk, gk, files, expect);
    }

    @Test
    void annoNestedClassTest(RunKind rk, GenKind gk) throws Exception {
        List<File> files = new ArrayList<File>();
        files.add(createFile("p/C.java",
                "class C { class Inner { @java.lang.annotation.Native public static final int i = 1907; } }"));

        Set<String> expect = createSet("C_Inner.h");
        if (gk == GenKind.FULL) expect.add("C.h");

        test(rk, gk, files, expect);
    }

    
    void test(RunKind rk, GenKind gk, List<File> files, Set<String> expect) throws Exception {
        List<String> args = new ArrayList<String>();
        if (gk == GenKind.FULL)
            args.add("-XDjavah:full");

        switch (rk) {
            case CMD:
                args.add("-d");
                args.add(classesDir.getPath());
                args.add("-h");
                args.add(headersDir.getPath());
                for (File f: files)
                    args.add(f.getPath());
                int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]));
                if (rc != 0)
                    throw new Exception("compilation failed, rc=" + rc);
                break;

            case API:
                fm.setLocation(StandardLocation.SOURCE_PATH, Arrays.asList(srcDir));
                fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(classesDir));
                fm.setLocation(StandardLocation.NATIVE_HEADER_OUTPUT, Arrays.asList(headersDir));
                JavacTask task = javac.getTask(null, fm, null, args, null,
                        fm.getJavaFileObjectsFromFiles(files));
                if (!task.call())
                    throw new Exception("compilation failed");
                break;
        }

        Set<String> found = createSet(headersDir.list());
        checkEqual("header files", expect, found);
    }

    
    @Retention(RetentionPolicy.RUNTIME)
    @interface Test { }

    
    void run() throws Exception {
        javac = JavacTool.create();
        fm = javac.getStandardFileManager(null, null, null);

        for (RunKind rk: RunKind.values()) {
            for (GenKind gk: GenKind.values()) {
                for (Method m: getClass().getDeclaredMethods()) {
                    Annotation a = m.getAnnotation(Test.class);
                    if (a != null) {
                        init(rk, gk, m.getName());
                        try {
                            m.invoke(this, new Object[] { rk, gk });
                        } catch (InvocationTargetException e) {
                            Throwable cause = e.getCause();
                            throw (cause instanceof Exception) ? ((Exception) cause) : e;
                        }
                        System.err.println();
                    }
                }
            }
        }
        System.err.println(testCount + " tests" + ((errorCount == 0) ? "" : ", " + errorCount + " errors"));
        if (errorCount > 0)
            throw new Exception(errorCount + " errors found");
    }

    
    void init(RunKind rk, GenKind gk, String name) throws IOException {
        System.err.println("Test " + rk + " " + gk + " " + name);
        testCount++;

        testDir = new File(rk.toString().toLowerCase() + "_" + gk.toString().toLowerCase() + "-" + name);
        srcDir = new File(testDir, "src");
        srcDir.mkdirs();
        classesDir = new File(testDir, "classes");
        classesDir.mkdirs();
        headersDir = new File(testDir, "headers");
        headersDir.mkdirs();
    }

    
    File createFile(String path, final String body) throws IOException {
        File f = new File(srcDir, path);
        f.getParentFile().mkdirs();
        try (FileWriter out = new FileWriter(f)) {
            out.write(body);
        }
        return f;
    }

    
    <T> Set<T> createSet(T... items) {
        return new HashSet<T>(Arrays.asList(items));
    }

    
    <T> void checkEqual(String label, T expect, T found) {
        if ((found == null) ? (expect == null) : found.equals(expect))
            return;
        System.err.println("Error: mismatch");
        System.err.println("  expected: " + expect);
        System.err.println("     found: " + found);
        errorCount++;
    }

    
    JavacTool javac;
    StandardJavaFileManager fm;

    
    File testDir;
    File srcDir;
    File classesDir;
    File headersDir;

    
    int testCount;
    int errorCount;
}

