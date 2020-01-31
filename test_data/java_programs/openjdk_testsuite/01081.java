



import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;

import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;

import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.jvm.Profile;
import com.sun.tools.javac.jvm.Target;


public class ProfileOptionTest {
    public static void main(String... args) throws Exception {
        new ProfileOptionTest().run();
    }

    private final JavaCompiler javac = JavacTool.create();
    private final StandardJavaFileManager fm = javac.getStandardFileManager(null, null, null);


    

    @Test
    void testInvalidProfile_CommandLine() throws Exception {
        JavaFileObject fo = new StringJavaFileObject("Test.java", "class Test { }");
        String badName = "foo";
        List<String> opts = Arrays.asList("-profile", badName);
        StringWriter sw = new StringWriter();
        try {
            JavacTask task = (JavacTask) javac.getTask(sw, fm, null, opts, null,
                Arrays.asList(fo));
            throw new Exception("expected exception not thrown");
        } catch (IllegalArgumentException e) {
            
        }
    }

    @Test
    void testInvalidProfile_API() throws Exception {
        String badName = "foo";
        String[] opts = { "-profile", badName };
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(opts, pw);

        
        
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out.trim());

        if (!out.contains("invalid profile: " + badName)) {
            error("expected message not found");
        }
    }

    @Test
    void testTargetProfileCombinations() throws Exception {
        JavaFileObject fo = new StringJavaFileObject("Test.java", "class Test { }");
        for (Target t: Target.values()) {
            switch (t) {
                case JDK1_1: case JDK1_2: 
                    continue;
            }

            for (Profile p: Profile.values()) {
                List<String> opts = new ArrayList<String>();
                opts.addAll(Arrays.asList("-source", t.name, "-target", t.name));
                opts.add("-Xlint:-options"); 
                if (p != Profile.DEFAULT)
                    opts.addAll(Arrays.asList("-profile", p.name));
                StringWriter sw = new StringWriter();
                JavacTask task = (JavacTask) javac.getTask(sw, fm, null, opts, null,
                        Arrays.asList(fo));
                task.analyze();

                
                
                String out = sw.toString();
                if (!out.isEmpty())
                    System.err.println(out.trim());

                switch (t) {
                    case JDK1_8:
                        if (!out.isEmpty())
                            error("unexpected output from compiler");
                        break;
                    default:
                        if (p != Profile.DEFAULT
                                && !out.contains("profile " + p.name
                                    + " is not valid for target release " + t.name)) {
                            error("expected message not found");
                        }
                }
            }
        }
    }

    @Test
    void testClassesInProfiles() throws Exception {
        for (Profile p: Profile.values()) {
            for (Map.Entry<Profile, List<JavaFileObject>> e: testClasses.entrySet()) {
                for (JavaFileObject fo: e.getValue()) {
                    DiagnosticCollector<JavaFileObject> dl =
                            new DiagnosticCollector<JavaFileObject>();
                    List<String> opts = (p == Profile.DEFAULT)
                            ? Collections.<String>emptyList()
                            : Arrays.asList("-profile", p.name);
                    JavacTask task = (JavacTask) javac.getTask(null, fm, dl, opts, null,
                            Arrays.asList(fo));
                    task.analyze();

                    List<String> expectDiagCodes = (p.value >= e.getKey().value)
                            ? Collections.<String>emptyList()
                            : Arrays.asList("compiler.err.not.in.profile");

                    checkDiags(opts + " " + fo.getName(), dl.getDiagnostics(), expectDiagCodes);
                }
            }
        }
    }

    Map<Profile, List<JavaFileObject>> testClasses =
            new EnumMap<Profile, List<JavaFileObject>>(Profile.class);

    void initTestClasses() {
        
        
        init(Profile.COMPACT1,
                java.lang.String.class);

        init(Profile.COMPACT2,
                javax.xml.XMLConstants.class);

        init(Profile.COMPACT3,
                javax.sql.rowset.Predicate.class,
                com.sun.security.auth.PolicyFile.class); 

        init(Profile.DEFAULT,
                java.beans.BeanInfo.class,
                javax.management.remote.rmi._RMIServer_Stub.class); 
    }

    void init(Profile p, Class<?>... classes) {
        List<JavaFileObject> srcs = new ArrayList<JavaFileObject>();
        for (Class<?> c: classes) {
            String name = "T" + c.getSimpleName();
            String src =
                    "class T" + name + "{" + "\n" +
                    "    Class<?> c = " + c.getName() + ".class;\n" +
                    "}";
            srcs.add(new StringJavaFileObject(name + ".java", src));
        }
        testClasses.put(p, srcs);
    }

    void checkDiags(String msg, List<Diagnostic<? extends JavaFileObject>> diags, List<String> expectDiagCodes) {
        System.err.print(msg);
        if (diags.isEmpty())
            System.err.println(" OK");
        else {
            System.err.println();
            System.err.println(diags);
        }

        List<String> foundDiagCodes = new ArrayList<String>();
        for (Diagnostic<? extends JavaFileObject> d: diags)
            foundDiagCodes.add(d.getCode());

        if (!foundDiagCodes.equals(expectDiagCodes)) {
            System.err.println("Found diag codes:    " + foundDiagCodes);
            System.err.println("Expected diag codes: " + expectDiagCodes);
            error("expected diagnostics not found");
        }
    }

    
    @Retention(RetentionPolicy.RUNTIME)
    @interface Test { }

    
    void run() throws Exception {
        initTestClasses();

        for (Method m: getClass().getDeclaredMethods()) {
            Annotation a = m.getAnnotation(Test.class);
            if (a != null) {
                System.err.println(m.getName());
                try {
                    m.invoke(this, new Object[] { });
                } catch (InvocationTargetException e) {
                    Throwable cause = e.getCause();
                    throw (cause instanceof Exception) ? ((Exception) cause) : e;
                }
                System.err.println();
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;

    private static class StringJavaFileObject extends SimpleJavaFileObject {
        StringJavaFileObject(String name, String text) {
            super(URI.create(name), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public CharSequence getCharContent(boolean b) {
            return text;
        }
        private String text;
    }
}
