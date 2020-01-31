



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.tools.javac.file.*;
import com.sun.tools.javac.file.ZipArchive.ZipFileObject;
import com.sun.tools.javac.file.ZipFileIndexArchive.ZipFileIndexFileObject;

public class T6705935 {
    public static void main(String... args) throws Exception {
        new T6705935().run();
    }

    public void run() throws Exception {
        File java_home = new File(System.getProperty("java.home"));
        if (java_home.getName().equals("jre"))
            java_home = java_home.getParentFile();

        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);
        

        for (JavaFileObject fo: fm.list(StandardLocation.PLATFORM_CLASS_PATH,
                                        "java.lang",
                                        Collections.singleton(JavaFileObject.Kind.CLASS),
                                        false)) {
            test++;

            if (!(fo instanceof ZipFileObject || fo instanceof ZipFileIndexFileObject)) {
                System.out.println("Skip " + fo.getClass().getSimpleName() + " " + fo.getName());
                skip++;
                continue;
            }

            
            String p = fo.getName();
            int bra = p.indexOf("(");
            int ket = p.indexOf(")");
            
            if (bra == -1 || ket != p.length() -1)
                throw new Exception("unexpected path: " + p + "[" + bra + "," + ket + "," + p.length());
            String part1 = p.substring(0, bra);
            String part2 = p.substring(bra + 1, ket);
            
            if (part1.equals(part2) || !part1.startsWith(java_home.getPath()))
                throw new Exception("bad path: " + p);

        }

        if (test == 0)
            throw new Exception("no files found");

        if (skip == 0)
            System.out.println(test + " files found");
        else
            System.out.println(test + " files found, " + skip + " files skipped");

        if (test == skip)
            System.out.println("Warning: all files skipped; no platform classes found in zip files.");
    }

    private <T> List<T> asList(Iterable<? extends T> items) {
        List<T> list = new ArrayList<T>();
        for (T item: items)
            list.add(item);
        return list;
     }

    private int skip;
    private int test;
}
