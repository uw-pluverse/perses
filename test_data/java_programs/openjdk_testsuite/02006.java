



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import javax.tools.*;


public class T6920317 {
    public static void main(String... args) throws Exception {
        new T6920317().run(args);
    }

    
    enum Kind {
        
        NONE,
        
        OLD,
        
        NEW,
        
        GEN
    }

    void run(String... args) throws Exception {
        
        
        for (int i = 0; i < args.length; i++) {
            tests.add(Integer.valueOf(args[i]));
        }

        setup();

        
        
        for (Kind cmdLine: EnumSet.of(Kind.NONE, Kind.OLD)) {
            for (Kind srcPath: Kind.values()) {
                for (Kind clsPath: Kind.values()) {
                    try {
                        test(cmdLine, srcPath, clsPath);
                    } catch (Exception e) {
                        e.printStackTrace();
                        error("Exception " + e);
                        
                        
                    }
                }
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    
    void setup() throws Exception {
        
        
        test_java = writeFile("Test.java", "package p; @interface Test { String value(); }");
        
        File tmpClasses = new File("tmp.classes");
        compile(tmpClasses, new String[] { }, test_java);

        
        cl_pkgInfo_java = writeFile("cl/p/package-info.java", "@Test(\"CL\") package p;");

        
        sp_old = new File("src.old");
        writeFile("src.old/p/package-info.java", "@Test(\"SP_OLD\") package p;");

        
        cp_old = new File("classes.old");
        compile(cp_old, new String[] { "-classpath", tmpClasses.getPath() },
                writeFile("tmp.old/p/package-info.java", "@Test(\"CP_OLD\") package p;"));

        
        sp_new = new File("src.new");
        File old_class = new File(cp_old, "p/package-info.class");
        writeFile("src.new/p/package-info.java", "@Test(\"SP_NEW\") package p;", old_class);

        
        cp_new = new File("classes.new");
        File old_java = new File(sp_old, "p/package-info.java");
        compile(cp_new, new String[] { "-classpath", tmpClasses.getPath() },
                writeFile("tmp.new/p/package-info.java", "@Test(\"CP_NEW\") package p;", old_java));

        
        sp_gen = new File("src.gen");
        writeFile("src.gen/p/package-info.java", "@Test(\"SP_GEN\") package p;");

        
        cp_gen = new File("classes.gen");
        compile(cp_gen, new String[] { "-classpath", tmpClasses.getPath() },
                writeFile("tmp.gen/p/package-info.java", "@Test(\"CP_GEN\") package p;"));
    }

    void test(Kind cl, Kind sp, Kind cp) throws Exception {
        if (skip(cl, sp, cp))
            return;

        ++count;
        
        if (tests.size() > 0 && !tests.contains(count))
            return;

        System.err.println("Test " + count + " cl:" + cl + " sp:" + sp + " cp:" + cp);

        
        File test_tmp = new File("tmp.test" + count);
        test_tmp.mkdirs();

        
        List<String> opts = new ArrayList<String>();
        List<File> files = new ArrayList<File>();

        
        String expect = null;

        opts.add("-processorpath");
        String testClasses = System.getProperty("test.classes");
        String testClassPath = System.getProperty("test.class.path", testClasses);
        opts.add(testClassPath);
        opts.add("-processor");
        opts.add(Processor.class.getName());
        opts.add("-proc:only");
        opts.add("-d");
        opts.add(test_tmp.getPath());
        
        files.add(test_java);

        

        
        if (cl == Kind.OLD) {
            files.add(cl_pkgInfo_java);
            
            expect = "CL";
        }

        
        switch (sp) {
        case NONE:
            break;

        case OLD:
            opts.add("-sourcepath");
            opts.add(sp_old.getPath());
            if (expect == null && cp == Kind.NONE) {
                assert cl == Kind.NONE && cp == Kind.NONE;
                expect = "SP_OLD";
            }
            break;

        case NEW:
            opts.add("-sourcepath");
            opts.add(sp_new.getPath());
            if (expect == null) {
                assert cl == Kind.NONE && cp == Kind.OLD;
                expect = "SP_NEW";
            }
            break;

        case GEN:
            opts.add("-Agen=" + new File(sp_gen, "p/package-info.java"));
            assert cl == Kind.NONE && cp == Kind.NONE;
            expect = "SP_GEN";
            break;
        }

        
        switch (cp) {
        case NONE:
            break;

        case OLD:
            opts.add("-classpath");
            opts.add(cp_old.getPath());
            if (expect == null && sp == Kind.NONE) {
                assert cl == Kind.NONE && sp == Kind.NONE;
                expect = "CP_OLD";
            }
            break;

        case NEW:
            opts.add("-classpath");
            opts.add(cp_new.getPath());
            if (expect == null) {
                assert cl == Kind.NONE && sp == Kind.OLD;
                expect = "CP_NEW";
            }
            break;

        case GEN:
            opts.add("-Agen=" + new File(cp_gen, "p/package-info.class"));
            assert cl == Kind.NONE && sp == Kind.NONE;
            expect = "CP_GEN";
            break;
        }

        
        assert expect != null;
        opts.add("-Aexpect=" + expect);

        
        compile(opts, files);
    }

    
    boolean skip(Kind cl, Kind sp, Kind cp) {
        
        if (cl == Kind.NONE && sp == Kind.NONE && cp == Kind.NONE)
            return true;

        
        if (sp == Kind.OLD && cp == Kind.OLD)
            return true;

        
        if ((sp == Kind.NEW && cp != Kind.OLD) || (cp == Kind.NEW && sp != Kind.OLD))
            return true;

        
        if (sp == Kind.GEN && !(cl == Kind.NONE && cp == Kind.NONE) ||
            cp == Kind.GEN && !(cl == Kind.NONE && sp == Kind.NONE)) {
            return true;
        }

        
        return false;
    }

    
    File writeFile(String path, String body) throws Exception {
        File f = new File(path);
        if (f.getParentFile() != null)
            f.getParentFile().mkdirs();
        Writer out = new FileWriter(path);
        try {
            out.write(body);
        } finally {
            out.close();
        }
        return f;
    }

    
    File writeFile(String path, String body, File ref) throws Exception {
        for (int i = 0; i < 5; i++) {
            File f = writeFile(path, body);
            if (f.lastModified() > ref.lastModified())
                return f;
            Thread.sleep(2000);
        }
        throw new Exception("cannot create file " + path + " newer than " + ref);
    }

    
    void compile(File dir, String[] opts, File src) throws Exception {
        dir.mkdirs();
        List<String> opts2 = new ArrayList<String>();
        opts2.addAll(Arrays.asList("-d", dir.getPath()));
        opts2.addAll(Arrays.asList(opts));
        compile(opts2, Collections.singletonList(src));
    }

    
    void compile(List<String> opts, List<File> files) throws Exception {
        System.err.println("javac: " + opts + " " + files);
        List<String> args = new ArrayList<String>();
        args.addAll(opts);
        for (File f: files)
            args.add(f.getPath());
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.flush();
        if (sw.getBuffer().length() > 0)
            System.err.println(sw.toString());
        if (rc != 0)
            throw new Exception("compilation failed: rc=" + rc);
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    
    int count;

    
    int errors;

    
    Set<Integer> tests = new HashSet<Integer>();

    
    File test_java;
    File sp_old;
    File sp_new;
    File sp_gen;
    File cp_old;
    File cp_new;
    File cp_gen;
    File cl_pkgInfo_java;

    
    @SupportedOptions({ "gen", "expect" })
    public static class Processor extends JavacTestingAbstractProcessor {
        public boolean process(Set<? extends TypeElement> annots, RoundEnvironment renv) {
            round++;
            System.err.println("Round " + round + " annots:" + annots + " rootElems:" + renv.getRootElements());

            
            
            String gen = getOption("gen");
            if (round == 1 && gen != null) {
                try {
                    Filer filer = processingEnv.getFiler();
                    JavaFileObject f;
                    if (gen.endsWith(".java"))
                        f = filer.createSourceFile("p.package-info");
                    else
                        f = filer.createClassFile("p.package-info");
                    System.err.println("copy " + gen + " to " + f.getName());
                    write(f, read(new File(gen)));
                } catch (IOException e) {
                    error("Cannot create package-info file: " + e);
                }
            }

            
            
            if (renv.processingOver()) {
                System.err.println("final round");
                Elements eu = processingEnv.getElementUtils();
                TypeElement te = eu.getTypeElement("p.Test");
                PackageElement pe = eu.getPackageOf(te);
                System.err.println("final: te:" + te + " pe:" + pe);
                List<? extends AnnotationMirror> annos = pe.getAnnotationMirrors();
                System.err.println("final: annos:" + annos);
                if (annos.size() == 1) {
                    String expect = "@" + te + "(\"" + getOption("expect") + "\")";
                    String actual = annos.get(0).toString();
                    checkEqual("package annotations", actual, expect);
                } else {
                    error("Wrong number of annotations found: (" + annos.size() + ") " + annos);
                }
            }

            return true;
        }

        
        String getOption(String name) {
            return processingEnv.getOptions().get(name);
        }

        
        byte[] read(File file) {
            byte[] bytes = new byte[(int) file.length()];
            DataInputStream in = null;
            try {
                in = new DataInputStream(new FileInputStream(file));
                in.readFully(bytes);
            } catch (IOException e) {
                error("Error reading file: " + e);
            } finally {
                if (in != null) {
                    try {
                        in.close();
                    } catch (IOException e) {
                        error("Error closing file: " + e);
                    }
                }
            }
            return  bytes;
        }

        
        void write(JavaFileObject file, byte[] bytes) {
            OutputStream out = null;
            try {
                out = file.openOutputStream();
                out.write(bytes, 0, bytes.length);
            } catch (IOException e) {
                error("Error writing file: " + e);
            } finally {
                if (out != null) {
                    try {
                        out.close();
                    } catch (IOException e) {
                        error("Error closing file: " + e);
                    }
                }
            }
        }

        
        private void checkEqual(String label, String actual, String expect) {
            if (!actual.equals(expect)) {
                error("Unexpected value for " + label + "; actual=" + actual + ", expected=" + expect);
            }
        }

        
        void error(String msg) {
            Messager messager = processingEnv.getMessager();
            messager.printMessage(Diagnostic.Kind.ERROR, msg);
        }

        int round;
    }
}
