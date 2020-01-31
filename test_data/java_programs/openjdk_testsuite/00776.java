



import java.io.*;
import java.net.*;
import java.util.*;
import java.util.jar.*;
import java.util.zip.*;
import javax.tools.*;

import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Options;






public class T6877206 {
    public static void main(String... args) throws Exception {
        new T6877206().run();
    }

    Set<String> foundClasses = new TreeSet<String>();
    Set<String> foundJars = new TreeSet<String>();

    void run() throws Exception {
        File rt_jar = findRtJar();

        
        String[] entries = { "p/A.class", "p/resources/A-1.jpg" };

        
        

        test(createFileManager(), createDir("dir", entries), "p", entries.length);
        test(createFileManager(), createDir("a b/dir", entries), "p", entries.length);

        for (boolean useOptimizedZip: new boolean[] { false, true }) {
            test(createFileManager(useOptimizedZip), createJar("jar", entries), "p", entries.length);
            test(createFileManager(useOptimizedZip), createJar("jar jar", entries), "p", entries.length);

            for (boolean useSymbolFile: new boolean[] { false, true }) {
                test(createFileManager(useOptimizedZip, useSymbolFile), rt_jar, "java.lang.ref", -1);
            }
        }

        
        checkCoverage("classes", foundClasses,
                "RegularFileObject", "SymbolFileObject", "ZipFileIndexFileObject", "ZipFileObject");

        
        checkCoverage("jar files", foundJars,
                "ct.sym", "jar", "jar jar", "rt.jar");
    }

    
    void test(StandardJavaFileManager fm, File f, String pkg, int expect) throws Exception {
        JarURLConnection c;
        System.err.println("Test " + f);
        try {
            fm.setLocation(StandardLocation.CLASS_PATH, Collections.singleton(f));

            int count = 0;
            for (JavaFileObject fo: fm.list(StandardLocation.CLASS_PATH,
                    pkg, EnumSet.allOf(JavaFileObject.Kind.class), true)) {
                System.err.println("checking " + fo);
                
                foundClasses.add(fo.getClass().getSimpleName());
                testFileObject(fo);
                count++;
            }

            if (expect > 0 && count != expect)
                throw new Exception("wrong number of entries found: "
                        + count + ", expected " + expect);
        } finally {
            fm.close();
        }
    }

    void testFileObject(JavaFileObject fo) throws Exception {
        
        
        
        URI uri = fo.toUri();
        System.err.println("uri: " + uri);

        URLConnection urlconn = uri.toURL().openConnection();
        if (urlconn instanceof JarURLConnection) {
            JarURLConnection jarconn = (JarURLConnection) urlconn;
            File f = new File(jarconn.getJarFile().getName());
            
            foundJars.add(f.getName());
        }

        try {
            byte[] uriData = read(urlconn.getInputStream());
            byte[] foData = read(fo.openInputStream());
            if (!Arrays.equals(uriData, foData)) {
                if (uriData.length != foData.length)
                    throw new Exception("data size differs: uri data "
                            + uriData.length + " bytes, fo data " + foData.length+ " bytes");
                for (int i = 0; i < uriData.length; i++) {
                    if (uriData[i] != foData[i])
                    throw new Exception("unexpected data returned at offset " + i
                            + ", uri data " + uriData[i] + ", fo data " + foData[i]);
                }
                throw new AssertionError("cannot find difference");
            }
        } finally {
            
            
            
            
            
            
            if (urlconn instanceof JarURLConnection) {
                JarURLConnection jarconn = (JarURLConnection) urlconn;
                jarconn.getJarFile().close();
            }
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
        Context ctx = new Context();
        Options options = Options.instance(ctx);
        options.put("useOptimizedZip", Boolean.toString(useOptimizedZip));
        if (!useSymbolFile) {
            options.put("ignore.symbol.file", "true");
        }
        return new JavacFileManager(ctx, false, null);
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
}
