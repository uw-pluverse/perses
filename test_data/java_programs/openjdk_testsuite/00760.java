



import java.io.*;
import java.util.*;
import java.util.zip.*;
import javax.tools.*;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Options;

public class T6838467 {
    boolean fileSystemIsCaseSignificant = !new File("a").equals(new File("A"));

    enum FileKind {
        DIR("dir"),
        ZIP("zip"),
        ZIPFILEINDEX("zip");
        FileKind(String path) {
            file = new File(path);
        }
        final File file;
    };

    enum CompareKind {
        SAME {
            File other(File f) { return f; }
        },
        ABSOLUTE {
            File other(File f) { return f.getAbsoluteFile(); }
        },
        DIFFERENT {
            File other(File f) { return new File("not_" + f.getPath()); }
        },
        CASEEQUIV {
            File other(File f) { return new File(f.getPath().toUpperCase()); }
        };
        abstract File other(File f);
    };

    String[] paths = { "p/A.java", "p/B.java", "p/C.java" };

    public static void main(String... args) throws Exception {
        new T6838467().run();
    }

    void run() throws Exception {
        
        if (System.getProperty("os.name").toLowerCase().startsWith("windows")
                && fileSystemIsCaseSignificant) {
            error("fileSystemIsCaseSignificant is set on Windows.");
        }

        
        createTestDir(new File("dir"), paths);
        createTestDir(new File("not_dir"), paths);
        createTestZip(new File("zip"), paths);
        createTestZip(new File("not_zip"), paths);
        if (fileSystemIsCaseSignificant) {
            createTestDir(new File("DIR"), paths);
            createTestZip(new File("ZIP"), paths);
        }

        
        
        for (FileKind fk: FileKind.values()) {
            for (CompareKind ck: CompareKind.values()) {
                test(fk, ck);
            }
        }

        
        
        Set<String> expectClasses = new HashSet<String>(Arrays.asList(
                "RegularFileObject", "ZipFileObject", "ZipFileIndexFileObject" ));
        if (!foundClasses.equals(expectClasses)) {
            error("expected fileobject classes not found\n"
                    + "expected: " + expectClasses + "\n"
                    + "found: " + foundClasses);
        }

        if (errors > 0)
            throw new Exception(errors + " errors");
    }

    void test(FileKind fk, CompareKind ck) throws IOException {
        File f1 = fk.file;
        JavaFileManager fm1 = createFileManager(fk, f1);

        File f2 = ck.other(fk.file);
        JavaFileManager fm2 = createFileManager(fk, f2);

        try {
            
            
            
            
            
            int expect = (f1.getAbsoluteFile().equals(f2.getAbsoluteFile()) ? paths.length : 0);

            System.err.println("test " + (++count) + " " + fk + " " + ck + " " + f1 + " " + f2);
            test(fm1, fm2, expect);

        } finally {
            fm1.close();
            fm2.close();
        }
    }

    
    
    
    
    
    void test(JavaFileManager fm1, JavaFileManager fm2, int expectEqualCount) throws IOException {
        boolean foundFiles1 = false;
        boolean foundFiles2 = false;
        int foundEqualCount = 0;
        Set<JavaFileObject.Kind> kinds =  EnumSet.allOf(JavaFileObject.Kind.class);
        for (FileObject fo1: fm1.list(StandardLocation.CLASS_PATH, "p", kinds, false)) {
            foundFiles1 = true;
            foundClasses.add(fo1.getClass().getSimpleName());
            for (FileObject fo2: fm2.list(StandardLocation.CLASS_PATH, "p", kinds, false)) {
                foundFiles2 = true;
                foundClasses.add(fo1.getClass().getSimpleName());
                System.err.println("compare " + fo1 + " " + fo2);
                if (fo1.equals(fo2)) {
                    foundEqualCount++;
                    int hash1 = fo1.hashCode();
                    int hash2 = fo2.hashCode();
                    if (hash1 != hash2)
                        error("hashCode error: " + fo1 + " [" + hash1 + "] "
                                + fo2 + " [" + hash2 + "]");
                }
            }
        }
        if (!foundFiles1)
            error("no files found for file manager 1");
        if (!foundFiles2)
            error("no files found for file manager 2");
        
        if (foundEqualCount != expectEqualCount)
            error("expected matches not found: expected " + expectEqualCount + ", found " + foundEqualCount);
    }

    
    
    JavaFileManager createFileManager(FileKind fk, File classpath) throws IOException {
        StandardJavaFileManager fm = createFileManager(fk == FileKind.ZIP);
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(classpath));
        return fm;
    }

    JavacFileManager createFileManager(boolean useOptimizedZip) {
        Context ctx = new Context();
        Options options = Options.instance(ctx);
        options.put("useOptimizedZip", Boolean.toString(useOptimizedZip));
        return new JavacFileManager(ctx, false, null);
    }

    
    void createTestDir(File dir, String[] paths) throws IOException {
        for (String p: paths) {
            File file = new File(dir, p);
            file.getParentFile().mkdirs();
            FileWriter out = new FileWriter(file);
            try {
                out.write(p);
            } finally {
                out.close();
            }
        }
    }

    
    void createTestZip(File zip, String[] paths) throws IOException {
        if (zip.getParentFile() != null)
            zip.getParentFile().mkdirs();
        ZipOutputStream zos = new ZipOutputStream(new FileOutputStream(zip));
        try {
            for (String p: paths) {
                ZipEntry ze = new ZipEntry(p);
                zos.putNextEntry(ze);
                byte[] bytes = p.getBytes();
                zos.write(bytes, 0, bytes.length);
                zos.closeEntry();
            }
        } finally {
            zos.close();
        }
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int count;
    int errors;
    Set<String> foundClasses = new HashSet<String>();
}

