

import java.io.*;
import java.lang.reflect.Constructor;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Tester {

    final static File classesdir = new File(System.getProperty("test.classes", "."));

    private String classname;
    private File[] files;
    private File refFile;
    private int errors;
    private int warnings;
    private int diffGolden;

    
    static final Class visitors[] = {
        ClassFileVisitor.class,
        ReflectionVisitor.class
    };

    
    public static void main(String... args) throws Exception {
        if (args.length != 2) {
            throw new Error("A single class name and a golden file are expected as argument");
        }
        String testSrc = System.getProperty("test.src");
        String testName = args[0];
        String testGoldenFile = args[1];
        final String pattern = testName + ".*\\.class";
        File refFile = new File(testSrc, testGoldenFile);
        File[] files = classesdir.listFiles(new FileFilter() {
                public boolean accept(File f) {
                    return f.getName().matches(pattern);
                }
            });
        if (files.length == 0) {
            File file = new File(classesdir, testName + ".class");
            throw new Error(file.getPath() + " not found");
        }

        new Tester(testName, files, refFile).run();
    }

    public Tester(String name, File[] files, File refFile) {
        this.classname = name;
        this.files = files;
        this.refFile = refFile;
    }

    void run() throws Exception {

        
        for (Class<Visitor> vclass : visitors) {
            boolean compResult = false;
            try {
                String vname = vclass.getName();
                Constructor c = vclass.getConstructor(Tester.class);

                info("\nRun " + vname + " for " + classname + "\n");
                StringBuilder sb = new StringBuilder();
                for (File f : files) {
                    String fname = f.getName();
                    fname = fname.substring(0, fname.length() - 6);
                    Visitor v = (Visitor) c.newInstance(this);
                    try {
                        v.visitClass(fname, f,  sb);
                    } catch(Exception e) {
                        error("Uncaught exception in visitClass()");
                        e.printStackTrace();
                    }
                }
                String output = sb.toString();
                info(output);
                compResult = compareOutput(refFile, output);
            } catch(ReflectiveOperationException e) {
                warn("Class " + vclass.getName() + " ignored, not a Visitor");
                continue;
            }
            if (!compResult) {
                diffGolden++;
                error("The output from " + vclass.getName() + " did not match golden file.");
        }
        }

        if (0 != diffGolden)
            throw new Exception("Test output is not equal with golden file.");

        if(0 != warnings)
                System.err.println("Test generated " + warnings + " warnings");

        if(0 != errors)
            throw new Exception("Tester test failed with " +
                                errors + " errors");
    }
    
    boolean compareOutput(File refFile, String sb)
            throws FileNotFoundException, IOException {

        List<String> refFileList = Files.readAllLines(refFile.toPath(), StandardCharsets.UTF_8);
        List<String> sbList = Arrays.asList(sb.split("[\r\n]+"));
        
        List<String> sbOnly = new ArrayList<>(sbList);
        sbOnly.removeAll(refFileList);
        for (String line: sbOnly)
            error("unexpected line found: " + line);

        List<String> refOnly = new ArrayList<>(refFileList);
        refOnly.removeAll(sbList);
        for (String line: refOnly)
            error("expected line not found: " + line);

        return sbOnly.isEmpty() && refOnly.isEmpty();
    }

    abstract static  class Visitor {
        Tester tester;
        File classesdir;

        public Visitor(Tester tester) {
            this.tester = tester;
        }

        abstract void visitClass(final String classname, final File  cfile,
                final StringBuilder sb) throws Exception;

        public void error(String msg) {
            tester.error(msg);
        }

        public void warn(String msg) {
            tester.warn(msg);
        }
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    void warn(String msg) {
        System.err.println("Warning: " + msg);
        warnings++;
    }

    void info(String msg) {
        System.out.println(msg);
    }
}
