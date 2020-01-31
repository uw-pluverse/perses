



import java.io.*;
import java.util.*;
import java.util.jar.*;
import java.util.zip.*;
import javax.tools.*;

import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Options;



public class Test {
    public static void main(String... args) throws Exception {
        new Test().run();
    }

    Set<String> foundClasses = new TreeSet<String>();
    Set<String> foundJars = new TreeSet<String>();

    void run() throws Exception {
        File rt_jar = findRtJar();

        
        String[] entries = { "p/A.java", "p/A.class", "p/resources/A-1.html" };

        
        

        test(createFileManager(), createDir("dir", entries), "p", entries);
        test(createFileManager(), createDir("a b/dir", entries), "p", entries);

        for (boolean useOptimizedZip: new boolean[] { false, true }) {
            test(createFileManager(useOptimizedZip), createJar("jar", entries), "p", entries);
            test(createFileManager(useOptimizedZip), createJar("jar jar", entries), "p", entries);

            for (boolean useSymbolFile: new boolean[] { false, true }) {
                test(createFileManager(useOptimizedZip, useSymbolFile), rt_jar, "java.lang.ref", null);
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors found");

        
        checkCoverage("classes", foundClasses,
                "RegularFileObject", "SymbolFileObject", "ZipFileIndexFileObject", "ZipFileObject");

        
        checkCoverage("jar files", foundJars,
                "ct.sym", "jar", "jar jar", "rt.jar");
    }

    
    void test(StandardJavaFileManager fm, File f, String pkg, String[] entries) throws Exception {
        System.err.println("Test " + f);
        try {
            if (f.isDirectory()) {
                for (File dir: new File[] { f, f.getAbsoluteFile() }) {
                    for (String e: entries) {
                        JavaFileObject fo = fm.getJavaFileObjects(new File(dir, e)).iterator().next();
                        test(fo, dir, e);
                    }
                }
            }

            fm.setLocation(StandardLocation.CLASS_PATH, Collections.singleton(f));
            fm.setLocation(StandardLocation.SOURCE_PATH, Collections.singleton(f.getAbsoluteFile()));
            for (StandardLocation l: EnumSet.of(StandardLocation.CLASS_PATH, StandardLocation.SOURCE_PATH)) {
                for (JavaFileObject fo: fm.list(l, pkg, EnumSet.allOf(JavaFileObject.Kind.class), true)) {
                    
                    File dir = (l == StandardLocation.CLASS_PATH ? f : f.getAbsoluteFile());
                    char sep = (dir.isDirectory() ? File.separatorChar : '/');
                    String b = fm.inferBinaryName(l, fo);
                    String e = fo.getKind().extension;
                    test(fo, dir, b.replace('.', sep) + e);
                }
            }
        } finally {
            fm.close();
        }
    }

    void test(JavaFileObject fo, File dir, String p) {
        System.err.println("Test: " + fo);
        String expect = dir.isDirectory() ? new File(dir, p).getPath() : (dir.getPath() + "(" + p + ")");
        String found = fo.getName();
        
        String found2 = found.replaceAll("lib([\\\\/])ct.sym\\(META-INF/sym/rt.jar/", "jre$1lib$1rt.jar(");
        if (!expect.equals(found2)) {
            System.err.println("expected: " + expect);
            System.err.println("   found: " + found);
            if (!found.equals(found2))
                System.err.println("  found2: " + found2);
            error("Failed: " + fo);
        }

        
        foundClasses.add(fo.getClass().getSimpleName());

        if (found.contains("(")) {
            
            foundJars.add(new File(found.substring(0, found.indexOf("("))).getName());
        }
    }

    void checkCoverage(String label, Set<String> found, String... expect) throws Exception {
        Set<String> e = new TreeSet<String>(Arrays.asList(expect));
        if (!found.equals(e)) {
            e.removeAll(found);
            throw new Exception("expected " + label + " not used: " + e);
        }
    }

    JavacFileManager createFileManager() {
        return createFileManager(false, false);
    }

    JavacFileManager createFileManager(boolean useOptimizedZip) {
        return createFileManager(useOptimizedZip, false);
    }

    JavacFileManager createFileManager(boolean useOptimizedZip, boolean useSymbolFile) {
        Context c = new Context();
        Options options = Options.instance(c);

        options.put("useOptimizedZip", Boolean.toString(useOptimizedZip));

        if (!useSymbolFile) {
            options.put("ignore.symbol.file", "true");
        }
        return new JavacFileManager(c, false, null);
    }

    File createDir(String name, String... entries) throws Exception {
        File dir = new File(name);
        if (!dir.mkdirs())
            throw new Exception("cannot create directories " + dir);
        for (String e: entries) {
            writeFile(new File(dir, e), e);
        }
        return dir;
    }

    File createJar(String name, String... entries) throws IOException {
        File jar = new File(name);
        OutputStream out = new FileOutputStream(jar);
        try {
            JarOutputStream jos = new JarOutputStream(out);
            for (String e: entries) {
                jos.putNextEntry(new ZipEntry(e));
                jos.write(e.getBytes());
            }
            jos.close();
        } finally {
            out.close();
        }
        return jar;
    }

    File findRtJar() throws Exception {
        File java_home = new File(System.getProperty("java.home"));
        if (java_home.getName().equals("jre"))
            java_home = java_home.getParentFile();
        File rt_jar = new File(new File(new File(java_home, "jre"), "lib"), "rt.jar");
        if (!rt_jar.exists())
            throw new Exception("can't find rt.jar");
        return rt_jar;
    }

    byte[] read(InputStream in) throws IOException {
        byte[] data = new byte[1024];
        int offset = 0;
        try {
            int n;
            while ((n = in.read(data, offset, data.length - offset)) != -1) {
                offset += n;
                if (offset == data.length)
                    data = Arrays.copyOf(data, 2 * data.length);
            }
        } finally {
            in.close();
        }
        return Arrays.copyOf(data, offset);
    }

    void writeFile(File f, String s) throws IOException {
        f.getParentFile().mkdirs();
        FileWriter out = new FileWriter(f);
        try {
            out.write(s);
        } finally {
            out.close();
        }
    }

    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int errors;
}
