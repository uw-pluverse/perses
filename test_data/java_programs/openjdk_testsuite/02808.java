



import java.io.*;
import java.util.*;
import javax.tools.*;

import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Options;

import static javax.tools.JavaFileObject.Kind.*;
import static javax.tools.StandardLocation.*;



public class TestInferBinaryName {
    static final boolean IGNORE_SYMBOL_FILE = false;
    static final boolean USE_SYMBOL_FILE = true;
    static final boolean DONT_USE_ZIP_FILE_INDEX = false;
    static final boolean USE_ZIP_FILE_INDEX = true;

    public static void main(String... args) throws Exception {
        new TestInferBinaryName().run();
    }

    void run() throws Exception {
        
        testDirectory();
        testSymbolArchive();
        testZipArchive();
        testZipFileIndexArchive();
        testZipFileIndexArchive2();
        if (errors > 0)
            throw new Exception(errors + " error found");
    }

    void testDirectory() throws IOException {
        String testClassName = "p.A";
        JavaFileManager fm =
            getFileManager("test.classes", USE_SYMBOL_FILE, USE_ZIP_FILE_INDEX);
        test("testDirectory",
             fm, testClassName, "com.sun.tools.javac.file.RegularFileObject");
    }

    void testSymbolArchive() throws IOException {
        String testClassName = "java.lang.String";
        JavaFileManager fm =
            getFileManager("sun.boot.class.path", USE_SYMBOL_FILE, DONT_USE_ZIP_FILE_INDEX);
        test("testSymbolArchive",
             fm, testClassName, "com.sun.tools.javac.file.SymbolArchive$SymbolFileObject");
    }

    void testZipArchive() throws IOException {
        String testClassName = "java.lang.String";
        JavaFileManager fm =
            getFileManager("sun.boot.class.path", IGNORE_SYMBOL_FILE, DONT_USE_ZIP_FILE_INDEX);
        test("testZipArchive",
             fm, testClassName, "com.sun.tools.javac.file.ZipArchive$ZipFileObject");
    }

    void testZipFileIndexArchive() throws IOException {
        String testClassName = "java.lang.String";
        JavaFileManager fm =
            getFileManager("sun.boot.class.path", USE_SYMBOL_FILE, USE_ZIP_FILE_INDEX);
        test("testZipFileIndexArchive",
             fm, testClassName, "com.sun.tools.javac.file.ZipFileIndexArchive$ZipFileIndexFileObject");
    }

    void testZipFileIndexArchive2() throws IOException {
        String testClassName = "java.lang.String";
        JavaFileManager fm =
            getFileManager("sun.boot.class.path", IGNORE_SYMBOL_FILE, USE_ZIP_FILE_INDEX);
        test("testZipFileIndexArchive2",
             fm, testClassName, "com.sun.tools.javac.file.ZipFileIndexArchive$ZipFileIndexFileObject");
    }

    
    void test(String testName,
              JavaFileManager fm, String testClassName, String implClassName) throws IOException {
        JavaFileObject fo = fm.getJavaFileForInput(CLASS_PATH, testClassName, CLASS);
        if (fo == null) {
            System.err.println("Can't find " + testClassName);
            errors++;
            return;
        }

        String cn = fo.getClass().getName();
        String bn = fm.inferBinaryName(CLASS_PATH, fo);
        System.err.println(testName + " " + cn + " " + bn);
        check(cn, implClassName);
        check(bn, testClassName);
        System.err.println("OK");
    }

    JavaFileManager getFileManager(String classpathProperty,
                                   boolean symFileKind,
                                   boolean zipFileIndexKind)
            throws IOException {
        Context ctx = new Context();
        Options options = Options.instance(ctx);
        options.put("useOptimizedZip",
                Boolean.toString(zipFileIndexKind == USE_ZIP_FILE_INDEX));

        if (symFileKind == IGNORE_SYMBOL_FILE)
            options.put("ignore.symbol.file", "true");
        JavacFileManager fm = new JavacFileManager(ctx, false, null);
        List<File> path = getPath(System.getProperty(classpathProperty));
        fm.setLocation(CLASS_PATH, path);
        return fm;
    }

    List<File> getPath(String s) {
        List<File> path = new ArrayList<File>();
        for (String f: s.split(File.pathSeparator)) {
            if (f.length() > 0)
                path.add(new File(f));
        }
        
        return path;
    }

    void check(String found, String expect) {
        if (!found.equals(expect)) {
            System.err.println("Expected: " + expect);
            System.err.println("   Found: " + found);
            errors++;
        }
    }

    private int errors;
}

class A { }

