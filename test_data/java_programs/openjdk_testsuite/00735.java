



import java.io.*;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.util.Elements;
import javax.lang.model.util.Types;
import javax.tools.*;

import com.sun.tools.javac.api.JavacTaskImpl;


public class TestResolveError extends ToolTester {
    public static void main(String... args) throws Exception {
        new TestResolveError().run();
    }

    void run() throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        File file = new File(test_src, "TestResolveError.java");
        final Iterable<? extends JavaFileObject> compilationUnits =
            fm.getJavaFileObjects(new File[] {file});
        task = (JavacTaskImpl)tool.getTask(pw, fm, null, null, null, compilationUnits);
        elements = task.getElements();
        types = task.getTypes();

        Iterable<? extends TypeElement> toplevels;
        try {
            toplevels = task.enter(task.parse());
        } catch (IOException ex) {
            throw new AssertionError(ex);
        }

        for (TypeElement clazz : toplevels) {
            System.out.format("Testing %s:%n%n", clazz.getSimpleName());
            
            
            testParseType(clazz);
        }

        pw.close();

        String out = sw.toString();
        System.out.println(out);

        if (out.contains("com.sun.tools.javac.util"))
            throw new Exception("Unexpected output from compiler");
    }

    void testParseType(TypeElement clazz) {
        DeclaredType type = (DeclaredType)task.parseType("List<String>", clazz);
        for (Element member : elements.getAllMembers((TypeElement)type.asElement())) {
            TypeMirror mt = types.asMemberOf(type, member);
            System.out.format("%s : %s -> %s%n", member.getSimpleName(), member.asType(), mt);
        }
    }

    JavacTaskImpl task;
    Elements elements;
    Types types;
}
