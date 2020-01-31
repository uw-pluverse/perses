



import com.sun.source.tree.ClassTree;
import com.sun.source.tree.CompilationUnitTree;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.tree.JCTree;

import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class TypeAnnotationsPretty {
    private final JavaCompiler tool;

    TypeAnnotationsPretty() {
        tool = ToolProvider.getSystemJavaCompiler();
    }

    private List<String> matches = new LinkedList<String>();
    private List<String> mismatches = new LinkedList<String>();

    public static void main(String... args) throws Exception {
        TypeAnnotationsPretty tap = new TypeAnnotationsPretty();

        tap.runField("@TA()\nObject cls = null");
        tap.runField("@TA()\nObject cls = new @TA() Object()");

        tap.runField("@TA()\nList<@TB() Object> cls = null");
        tap.runField("@TA()\nList<@TB() Object> cls = new @TA() LinkedList<@TB() Object>()");

        tap.runField("Class[] cls = null");
        tap.runField("@TA()\nClass[] cls = null");
        tap.runField("Class @TA() [] cls = null");
        tap.runField("@TA()\nClass @TB() [] cls = null");

        tap.runField("Class[] cls = new Class[]{Object.class}");
        tap.runField("@TA()\nClass[] cls = new @TA() Class[]{Object.class}");
        tap.runField("Class @TB() [] cls = new Class @TB() []{Object.class}");
        tap.runField("@TA()\nClass @TB() [] cls = new @TA() Class @TB() []{Object.class}");
        tap.runField("@TA()\nClass @TB() [] @TC() [] cls = new @TA() Class @TB() [10] @TC() []");
        tap.runField("Class @TB() [] @TC() [] cls = new Class @TB() [10] @TC() []");
        tap.runField("@TA()\nClass @TB() [] @TC() [] @TD() [] cls = new @TA() Class @TB() [10] @TC() [] @TD() []");

        tap.runMethod("\n@TA()\nObject test(@TB()\nList<@TC() String> p) {\n" +
                "    return null;\n" +
                "}");


        if (!tap.matches.isEmpty()) {
            for (String m : tap.matches)
                System.out.println(m);
        }
        if (!tap.mismatches.isEmpty()) {
            for (String mm : tap.mismatches)
                System.err.println(mm + NL);
            throw new RuntimeException("Tests failed!");
        }
    }

    private static final String prefix =
            "import java.lang.annotation.*;" +
            "import java.util.*;" +
            "public class Test {";

    private static final String postfix =
            "@Target(ElementType.TYPE_USE)" +
            "@interface TA {}" +
            "@Target(ElementType.TYPE_USE)" +
            "@interface TB {}" +
            "@Target(ElementType.TYPE_USE)" +
            "@interface TC {}" +
            "@Target(ElementType.TYPE_USE)" +
            "@interface TD {}";

    private static final String NL = System.getProperty("line.separator");

    private void runField(String code) throws IOException {
        String src = prefix +
                code + "; }" +
                postfix;

        JavacTaskImpl ct = (JavacTaskImpl) tool.getTask(null, null, null, null,
                null, Arrays.asList(new MyFileObject(src)));

        for (CompilationUnitTree cut : ct.parse()) {
            JCTree.JCVariableDecl var =
                    (JCTree.JCVariableDecl) ((ClassTree) cut.getTypeDecls().get(0)).getMembers().get(0);
            checkMatch(code, var);
        }
    }

    private void runMethod(String code) throws IOException {
        String src = prefix +
                code + "}" +
                postfix;

        JavacTaskImpl ct = (JavacTaskImpl) tool.getTask(null, null, null, null,
                null, Arrays.asList(new MyFileObject(src)));


        for (CompilationUnitTree cut : ct.parse()) {
            JCTree.JCMethodDecl meth =
                    (JCTree.JCMethodDecl) ((ClassTree) cut.getTypeDecls().get(0)).getMembers().get(0);
            checkMatch(code, meth);
        }
    }

    void checkMatch(String code, JCTree tree) {
        String expect = code.replace("\n", NL);
        String found = tree.toString();
        if (!expect.equals(found)) {
            mismatches.add("Expected: " + expect + NL +
                    "Obtained: " + found);
        } else {
            matches.add("Passed: " + expect);
        }
    }
}


class MyFileObject extends SimpleJavaFileObject {

    private String text;

    public MyFileObject(String text) {
        super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
        this.text = text;
    }

    @Override
    public CharSequence getCharContent(boolean ignoreEncodingErrors) {
        return text;
    }
}
