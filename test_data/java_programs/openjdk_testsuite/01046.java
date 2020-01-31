



import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;

@SupportedAnnotationTypes("*")
public class T6423583 extends AbstractProcessor {
    boolean b1 = true;
    boolean b2 = false;
    String s = "s";
    char c = 'c';
    int i = 0;
    long l = 0l;
    float f = 0f;
    double d = 0d;
    Void v = null;

    public boolean process(Set<? extends TypeElement> annos, RoundEnvironment rEnv) {
        Trees trees = Trees.instance(processingEnv);
        Test test = new Test();
        for (Element e: rEnv.getRootElements()) {
            Tree t = trees.getTree(e);
            test.scan(t, null);
        }
        return true;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    private static class Test extends TreeScanner<Void,Void> {

        private static Map<Tree.Kind, Class> map = new HashMap<Tree.Kind, Class>();
        static {
            map.put(Tree.Kind.BOOLEAN_LITERAL, Boolean.class);
            map.put(Tree.Kind.CHAR_LITERAL, Character.class);
            map.put(Tree.Kind.STRING_LITERAL, String.class);
            map.put(Tree.Kind.INT_LITERAL, Integer.class);
            map.put(Tree.Kind.LONG_LITERAL, Long.class);
            map.put(Tree.Kind.FLOAT_LITERAL, Float.class);
            map.put(Tree.Kind.DOUBLE_LITERAL, Double.class);
        }

        public Void visitLiteral(LiteralTree tree, Void ignore) {
            System.err.println(tree);
            Class expect = map.get(tree.getKind());
            if (!check(tree.getValue(), expect)) {
                System.err.println("tree: " + tree);
                System.err.println("expected class: " + expect);
                if (tree.getValue() != null)
                    System.err.println("actual class: " + tree.getValue().getClass());
                throw new AssertionError("unexpected value for literal");
            }
            return null;
        }

        private boolean check(Object value, Class<?> expectedClass) {
            return (value == null ? expectedClass == null : value.getClass().equals(expectedClass));
        }
    }
}
