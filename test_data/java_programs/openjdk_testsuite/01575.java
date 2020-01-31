

package org.openjdk.tests.javac;

import org.openjdk.tests.shapegen.*;

import com.sun.source.util.JavacTask;
import com.sun.tools.javac.util.Pair;

import java.net.URI;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import javax.tools.Diagnostic;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import org.testng.annotations.Test;
import org.testng.annotations.BeforeSuite;
import org.testng.annotations.DataProvider;
import static org.testng.Assert.*;

public class FDTest {

    public enum TestKind {
        POSITIVE,
        NEGATIVE;

        Collection<Hierarchy> getHierarchy(HierarchyGenerator hg) {
            return this == POSITIVE ?
                    hg.getOK() : hg.getErr();
        }
    }

    public static JavaCompiler comp;
    public static StandardJavaFileManager fm;

    @BeforeSuite
    static void init() {
        
        

        comp = ToolProvider.getSystemJavaCompiler();
        fm = comp.getStandardFileManager(null, null, null);
    }

    public static void main(String[] args) throws Exception {
        init();

        for (Pair<TestKind,Hierarchy> fdtest : generateCases()) {
            runTest(fdtest.fst, fdtest.snd, comp, fm);
        }
    }

    @Test(dataProvider = "fdCases")
    public void testOneCase(TestKind tk, Hierarchy hs)
            throws Exception {
        FDTest.runTest(tk, hs, comp, fm);
    }

    @DataProvider(name = "fdCases")
    public Object[][] caseGenerator() {
        List<Pair<TestKind, Hierarchy>> cases = generateCases();
        Object[][] fdCases = new Object[cases.size()][];
        for (int i = 0; i < cases.size(); ++i) {
            fdCases[i] = new Object[2];
            fdCases[i][0] = cases.get(i).fst;
            fdCases[i][1] = cases.get(i).snd;
        }
        return fdCases;
    }

    public static List<Pair<TestKind, Hierarchy>> generateCases() {
        ArrayList<Pair<TestKind,Hierarchy>> list = new ArrayList<>();
        HierarchyGenerator hg = new HierarchyGenerator();
        for (TestKind tk : TestKind.values()) {
            for (Hierarchy hs : tk.getHierarchy(hg)) {
                list.add(new Pair<>(tk, hs));
            }
        }
        return list;
    }

    public static void runTest(TestKind tk, Hierarchy hs,
            JavaCompiler comp, StandardJavaFileManager fm) throws Exception {
        new FDTest(tk, hs).run(comp, fm);
    }

    TestKind tk;
    Hierarchy hs;
    DefenderTestSource source;
    DiagnosticChecker diagChecker;

    public FDTest() {}

    FDTest(TestKind tk, Hierarchy hs) {
        this.tk = tk;
        this.hs = hs;
        this.source = new DefenderTestSource();
        this.diagChecker = new DiagnosticChecker();
    }

    void run(JavaCompiler tool, StandardJavaFileManager fm) throws Exception {
        JavacTask ct = (JavacTask)tool.getTask(null, fm, diagChecker,
                null, null, Arrays.asList(source));
        try {
            ct.analyze();
        } catch (Throwable ex) {
            fail("Error thrown when analyzing the following source:\n" + source.getCharContent(true));
        }
        check();
    }

    void check() {
        boolean errorExpected = tk == TestKind.NEGATIVE;
        if (errorExpected != diagChecker.errorFound) {
            fail("problem in source: \n" +
                 "\nerror found = " + diagChecker.errorFound +
                 "\nerror expected = " + errorExpected +
                 "\n" + dumpHierarchy() +
                 "\n" + source.getCharContent(true));
        }
    }

    String dumpHierarchy() {
        StringBuilder buf = new StringBuilder();
        buf.append("root = " + hs.root + "\n");
        for (ClassCase cc : hs.all) {
            buf.append("  class name = " + cc.getName() + "\n");
            buf.append("    class OK = " + cc.get_OK() + "\n");
            buf.append("    prov = " + cc.get_mprov() + "\n");

        }
        return buf.toString();
    }

    class DefenderTestSource extends SimpleJavaFileObject {

        String source;

        public DefenderTestSource() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            StringBuilder buf = new StringBuilder();
            List<ClassCase> defaultRef = new ArrayList<>();
            for (ClassCase cc : hs.all) {
                Hierarchy.genClassDef(buf, cc, null, defaultRef);
            }
            source = buf.toString();
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    static class DiagnosticChecker implements javax.tools.DiagnosticListener<JavaFileObject> {

        boolean errorFound;

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR) {
                errorFound = true;
            }
        }
    }
}
