



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.tools.*;


public class T6341866 {
    static final String testSrc = System.getProperty("test.src", ".");
    static final String testClasses = System.getProperty("test.classes", ".");
    static final File a_java = new File(testSrc, "A.java");
    static final File a_class = new File("A.class");
    static final File b_java = new File(testSrc, "B.java");
    static final File b_class = new File("B.class");
    static final File processorServices = services(Processor.class);

    enum ImplicitType {
        NONE(null),                     
        OPT_UNSET(null),                
        OPT_NONE("-implicit:none"),     
        OPT_CLASS("-implicit:class");   

        ImplicitType(String opt) {
            this.opt = opt;
        }
        final String opt;
    };

    enum AnnoType {
        NONE,           
        SERVICE,        
        SPECIFY         
    };


    public static void main(String ... args) throws Exception {
        boolean ok = true;

        
        for (ImplicitType implicitType: EnumSet.allOf(ImplicitType.class)) {
            for (AnnoType annoType: EnumSet.allOf(AnnoType.class)) {
                ok &= test(implicitType, annoType);
            }
        }

        if (!ok)
            throw new AssertionError("test failed");
    }

    
    static boolean test(ImplicitType implicitType, AnnoType annoType) throws IOException {
        System.err.println("test  implicit=" + implicitType + "  anno=" + annoType);

        
        a_class.delete();
        b_class.delete();
        processorServices.delete();

        List<String> opts = new ArrayList<String>();
        opts.addAll(Arrays.asList("-d", ".", "-sourcepath", testSrc, "-classpath", testClasses, "-source", "1.6", "-Xlint:-options"));
        if (implicitType.opt != null)
            opts.add(implicitType.opt);

        switch (annoType) {
        case SERVICE:
            createProcessorServices(Anno.class.getName());
            break;
        case SPECIFY:
            opts.addAll(Arrays.asList("-processor", Anno.class.getName()));
            break;
        }


        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        MyDiagListener dl = new MyDiagListener();
        StandardJavaFileManager fm = javac.getStandardFileManager(dl, null, null);

        
        File file =  (implicitType != ImplicitType.NONE) ? a_java : b_java;
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(file);

        

        boolean ok = javac.getTask(null, fm, dl, opts, null, files).call();
        if (!ok) {
            error("compilation failed");
            return false;
        }

        
        if (implicitType != ImplicitType.NONE) {
            boolean expectClass = (implicitType != ImplicitType.OPT_NONE);
            if (b_class.exists() != expectClass) {
                if (b_class.exists())
                    error("B implicitly compiled unexpectedly");
                else
                    error("B not impliictly compiled");
                return false;
            }
        }

        
        String expectKey = null;
        if (implicitType == ImplicitType.OPT_UNSET) {
            switch (annoType) {
            case SERVICE:
                expectKey = "compiler.warn.proc.use.proc.or.implicit";
                break;
            case SPECIFY:
                expectKey = "compiler.warn.proc.use.implicit";
                break;
            }
        }

        if (expectKey == null) {
            if (dl.diagCodes.size() != 0) {
                error("no diagnostics expected");
                return false;
            }
        } else {
            if (!(dl.diagCodes.size() == 1 && dl.diagCodes.get(0).equals(expectKey))) {
                error("unexpected diagnostics generated");
                return false;
            }
        }

        return true;
    }

    static void createProcessorServices(String name) throws IOException {
        processorServices.getParentFile().mkdirs();

        BufferedWriter out = new BufferedWriter(new FileWriter(processorServices));
        out.write(name);
        out.newLine();
        out.close();
    }

    static class MyDiagListener implements DiagnosticListener<JavaFileObject> {
        public void report(Diagnostic d) {
            diagCodes.add(d.getCode());
            System.err.println(d);
        }

        List<String> diagCodes = new ArrayList<String>();
    }

    static void error(String msg) {
        System.err.println("ERROR: " + msg);
    }

    static File services(Class<?> service) {
        String[] dirs = { testClasses, "META-INF", "services" };
        File dir = null;
        for (String d: dirs)
            dir = (dir == null ? new File(d) : new File(dir, d));

        return new File(dir, service.getName());
    }
}
