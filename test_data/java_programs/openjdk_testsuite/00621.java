



import java.nio.file.Files;
import java.nio.file.Paths;

public class DefaultMethodsNotVisibleForSourceLessThan8Test {
    

    
    static final String ISrc =
        "interface I {\n" +
        "    default void m() {}\n" +
        "}";

    static final String JSrc =
        "interface J extends I {}";

    static final String ASrc =
        "abstract class A implements I {}";

    static final String BSrc =
        "class B implements I {}";

    
    static final String C1Src =
        "class C1 implements I {\n" +
        "    public void m() {}\n" +
        "}";

    static final String C2Src =
        "class C2 implements J {\n" +
        "    public void m() {}\n" +
        "}";

    static final String C3Src =
        "class C3 extends A {\n" +
        "    public void m() {}\n" +
        "}";

    static final String C4Src =
        "class C4 extends B {\n" +
        "    public void m() {}\n" +
        "}";

    
    static final String LegacyInvocationSrc =
        "class LegacyInvocation {\n" +
        "    public static void test(I i, J j, A a, B b) {\n" +
        "        i.m();\n" +
        "        j.m();\n" +
        "        a.m();\n" +
        "        b.m();\n" +
        "    }\n" +
        "}";

    
    static final String SubASrc =
        "class SubA extends A {\n" +
        "    public void test() {\n" +
        "        super.m();\n" +
        "    }\n" +
        "}";

    static final String SubBSrc =
        "class SubB extends B {\n" +
        "    public void test() {\n" +
        "        super.m();\n" +
        "    }\n" +
        "}";

    public static void main(String[] args) throws Exception {
        String[] sources = new String[] {
            "1.2",
            "1.3",
            "1.4",
            "1.5",
            "1.6",
            "1.7",
        };
        for (String source : sources) {
            new DefaultMethodsNotVisibleForSourceLessThan8Test().run(source);
        }
    }

    String outDir;
    String source;

    void run(String source) throws Exception {
        this.source = source;
        outDir = "out" + source.replace('.', '_');
        testsPreparation();
        testLegacyImplementations();
        testLegacyInvocations();
        testSuperInvocations();
    }

    void testsPreparation() throws Exception {
        Files.createDirectory(Paths.get(outDir));

        
        ToolBox.JavaToolArgs javacArgs =
                new ToolBox.JavaToolArgs(ToolBox.Expect.FAIL)
                .setOptions("-d", outDir, "-source", source)
                .setSources(ISrc);
        ToolBox.javac(javacArgs);

        
        javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-d", outDir)
                .setSources(ISrc);
        ToolBox.javac(javacArgs);

        javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-cp", outDir, "-d", outDir, "-source", source)
                .setSources(JSrc, ASrc, BSrc);
        ToolBox.javac(javacArgs);
    }

    void testLegacyImplementations() throws Exception {
        
        ToolBox.JavaToolArgs javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-cp", outDir, "-d", outDir, "-source", source)
                .setSources(C1Src, C2Src, C3Src, C4Src);
        ToolBox.javac(javacArgs);
    }

    void testLegacyInvocations() throws Exception {
        
        ToolBox.JavaToolArgs javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-cp", outDir, "-d", outDir, "-source", source)
                .setSources(LegacyInvocationSrc);
        ToolBox.javac(javacArgs);
    }

    void testSuperInvocations() throws Exception {
        
        ToolBox.JavaToolArgs javacArgs =
                new ToolBox.JavaToolArgs()
                .setOptions("-cp", outDir, "-d", outDir, "-source", source)
                .setSources(SubASrc, SubBSrc);
        ToolBox.javac(javacArgs);
    }
}
