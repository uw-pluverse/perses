



import com.sun.source.tree.CatchTree;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.source.util.TreePath;

import java.util.Set;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.type.TypeKind;
import javax.lang.model.type.UnionType;
import javax.lang.model.type.UnknownTypeException;
import javax.lang.model.util.SimpleTypeVisitor6;
import javax.lang.model.util.SimpleTypeVisitor7;

@SupportedAnnotationTypes("Check")
public class ModelChecker extends JavacTestingAbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        if (roundEnv.processingOver())
            return true;

        Trees trees = Trees.instance(processingEnv);

        TypeElement testAnno = elements.getTypeElement("Check");
        for (Element elem: roundEnv.getElementsAnnotatedWith(testAnno)) {
            TreePath p = trees.getPath(elem);
            new MulticatchParamTester(trees).scan(p, null);
        }
        return true;
    }

    class MulticatchParamTester extends TreePathScanner<Void, Void> {
        Trees trees;

        public MulticatchParamTester(Trees trees) {
            super();
            this.trees = trees;
        }

        @Override
        public Void visitCatch(CatchTree node, Void p) {
            TreePath param = new TreePath(getCurrentPath(), node.getParameter());
            Element ex = trees.getElement(param);
            validateUnionTypeInfo(ex);
            if (ex.getSimpleName().contentEquals("ex")) {
                assertTrue(ex.getKind() == ElementKind.EXCEPTION_PARAMETER, "Expected EXCEPTION_PARAMETER - found " + ex.getKind());
                for (Element e : types.asElement(trees.getLub(node)).getEnclosedElements()) {
                    Member m = e.getAnnotation(Member.class);
                    if (m != null) {
                        assertTrue(e.getKind() == m.value(), "Expected " + m.value() + " - found " + e.getKind());
                    }
                }
                assertTrue(assertionCount == 9, "Expected 9 assertions - found " + assertionCount);
            }
            return super.visitCatch(node, p);
        }
    }

    private void validateUnionTypeInfo(Element ex) {
        UnionTypeInfo ut = ex.getAnnotation(UnionTypeInfo.class);
        assertTrue(ut != null, "UnionType annotation must be present");

        TypeMirror expectedUnionType = ex.asType();
        assertTrue(expectedUnionType.getKind() == TypeKind.UNION, "UNION kind expected");

        try {
            new SimpleTypeVisitor6<Void, Void>(){}.visit(expectedUnionType);
            throw new RuntimeException("Expected UnknownTypeException not thrown.");
        } catch (UnknownTypeException ute) {
            ; 
        }

        UnionType unionType = new SimpleTypeVisitor<UnionType, Void>(){
            @Override
            protected UnionType defaultAction(TypeMirror e, Void p) {return null;}

            @Override
            public UnionType visitUnion(UnionType t, Void p) {return t;}
        }.visit(expectedUnionType);
        assertTrue(unionType != null, "Must get a non-null union type.");

        assertTrue(ut.value().length == unionType.getAlternatives().size(), "Cardinalities do not match");

        String[] typeNames = ut.value();
        for(int i = 0; i < typeNames.length; i++) {
            TypeMirror typeFromAnnotation = nameToType(typeNames[i]);
            assertTrue(types.isSameType(typeFromAnnotation, unionType.getAlternatives().get(i)),
                       "Types were not equal.");
        }
    }

    private TypeMirror nameToType(String name) {
        return elements.getTypeElement(name).asType();
    }

    private static void assertTrue(boolean cond, String msg) {
        assertionCount++;
        if (!cond)
            throw new AssertionError(msg);
    }

    static int assertionCount = 0;
}
