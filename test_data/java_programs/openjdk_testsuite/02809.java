

import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import javax.tools.*;

import com.sun.source.util.*;
import com.sun.tools.javac.code.BoundKind;
import com.sun.tools.javac.tree.JCTree.*;
import com.sun.tools.javac.tree.TreeScanner;
import com.sun.tools.javac.tree.*;
import com.sun.tools.javac.util.List;


@SupportedAnnotationTypes({"Test"})
public class TestProcessor extends AbstractProcessor {
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    
    public boolean process(Set<? extends TypeElement> annos, RoundEnvironment renv) {
        if (renv.processingOver())
            return true;

        Elements elements = processingEnv.getElementUtils();
        Trees trees = Trees.instance(processingEnv);

        TypeElement testAnno = elements.getTypeElement("Test");
        for (Element elem: renv.getElementsAnnotatedWith(testAnno)) {
            System.err.println("ELEM: " + elem);
            int count = getValue(getAnnoMirror(elem, testAnno), Integer.class);
            System.err.println("count: " + count);
            TreePath p = trees.getPath(elem);
            JavaFileObject file = p.getCompilationUnit().getSourceFile();
            JCTree tree = (JCTree) p.getLeaf();
            System.err.println("tree: " + tree);
            new TestScanner(file).check(tree, count);
        }
        return true;
    }

    
    AnnotationMirror getAnnoMirror(Element e, TypeElement anno) {
        Types types = processingEnv.getTypeUtils();
        for (AnnotationMirror m: e.getAnnotationMirrors()) {
            if (types.isSameType(m.getAnnotationType(), anno.asType()))
                return m;
        }
        return null;
    }

    
    <T> T getValue(AnnotationMirror m, Class<T> type) {
        for (Map.Entry<? extends ExecutableElement,? extends AnnotationValue> e: m.getElementValues().entrySet()) {
            ExecutableElement ee = e.getKey();
            if (ee.getSimpleName().contentEquals("value")) {
                AnnotationValue av = e.getValue();
                return type.cast(av.getValue());
            }
        }
        return null;
    }

    
    void error(String msg) {
        Messager messager = processingEnv.getMessager();
        messager.printMessage(Diagnostic.Kind.ERROR, msg);
    }

    
    void error(JavaFileObject file, JCTree tree, String msg) {
        
        Messager messager = processingEnv.getMessager();
        String text = file.getName() + ":" + getLine(file, tree) + ": " + msg;
        messager.printMessage(Diagnostic.Kind.ERROR, text);
    }

    
    int getLine(JavaFileObject file, JCTree tree) {
        try {
            CharSequence cs = file.getCharContent(true);
            int line = 1;
            for (int i = 0; i < tree.pos; i++) {
                if (cs.charAt(i) == '\n') 
                    line++;
            }
            return line;
        } catch (IOException e) {
            return -1;
        }
    }

    
    class TestScanner extends TreeScanner {
        
        TestScanner(JavaFileObject file) {
            this.file = file;
        }

        
        void check(JCTree tree, int expectCount) {
            foundCount = 0;
            scan(tree);
            if (foundCount != expectCount)
                error(file, tree, "Wrong number of annotations found: " + foundCount + ", expected: " + expectCount);
        }

        
        @Override
        public void visitClassDef(JCClassDecl tree) {
            super.visitClassDef(tree);
            check(tree.mods.annotations, "DA", tree);
        }

        
        @Override
        public void visitMethodDef(JCMethodDecl tree) {
            super.visitMethodDef(tree);
            check(tree.mods.annotations, "DA", tree);
        }

        
        @Override
        public void visitVarDef(JCVariableDecl tree) {
            super.visitVarDef(tree);
            check(tree.mods.annotations, "DA", tree);
        }

        
        public void visitAnnotatedType(JCAnnotatedType tree) {
            super.visitAnnotatedType(tree);
            check(tree.annotations, "TA", tree);
        }

        
        void check(List<? extends JCAnnotation> annos, String name, JCTree tree) {
            for (List<? extends JCAnnotation> l = annos; l.nonEmpty(); l = l.tail) {
                JCAnnotation anno = l.head;
                if (anno.annotationType.toString().equals(name) && (anno.args.size() == 1)) {
                    String expect = getStringValue(anno.args.head);
                    foundCount++;
                    System.err.println("found: " + name + " " + expect);
                    String found = new TypePrinter().print(tree);
                    if (!found.equals(expect))
                        error(file, anno, "Unexpected result: expected: \"" + expect + "\", found: \"" + found + "\"");
                }
            }
        }

        
        String getStringValue(JCExpression e) {
            if (e.hasTag(JCTree.Tag.ASSIGN)) {
                JCAssign a = (JCAssign) e;
                JCExpression rhs = a.rhs;
                if (rhs.hasTag(JCTree.Tag.LITERAL)) {
                    JCLiteral l = (JCLiteral) rhs;
                    return (String) l.value;
                }
            } else if (e.hasTag(JCTree.Tag.LITERAL)) {
                JCLiteral l = (JCLiteral) e;
                return (String) l.value;
            }
            throw new IllegalArgumentException(e.toString());
        }

        
        JavaFileObject file;
        
        int foundCount;
    }

    
    class TypePrinter extends Visitor {
        
        String print(JCTree tree) {
            if (tree == null)
                return null;
            tree.accept(this);
            return result;
        }

        String print(List<? extends JCTree> list) {
            return print(list, ", ");
        }

        String print(List<? extends JCTree> list, String sep) {
            StringBuilder sb = new StringBuilder();
            if (list.nonEmpty()) {
                sb.append(print(list.head));
                for (List<? extends JCTree> l = list.tail; l.nonEmpty(); l = l.tail) {
                    sb.append(sep);
                    sb.append(print(l.head));
                }
            }
            return sb.toString();
        }

        @Override
        public void visitClassDef(JCClassDecl tree) {
            result = tree.name.toString();
        }

        @Override
        public void visitMethodDef(JCMethodDecl tree) {
            result = tree.name.toString();
        }

        @Override
        public void visitVarDef(JCVariableDecl tree) {
            tree.vartype.accept(this);
        }

        @Override
        public void visitAnnotatedType(JCAnnotatedType tree) {
            tree.underlyingType.accept(this);
        }

        @Override
        public void visitTypeIdent(JCPrimitiveTypeTree tree) {
            result = tree.toString();
        }

        @Override
        public void visitTypeArray(JCArrayTypeTree tree) {
            result = print(tree.elemtype) + "[]";
        }

        @Override
        public void visitTypeApply(JCTypeApply tree) {
            result = print(tree.clazz) + "<" + print(tree.arguments) + ">";
        }

        @Override
        public void visitTypeParameter(JCTypeParameter tree) {
            if (tree.bounds.isEmpty())
                result = tree.name.toString();
            else
                result = tree.name + " extends " + print(tree.bounds, "&");
        }

        @Override
        public void visitWildcard(JCWildcard tree) {
            if (tree.kind.kind == BoundKind.UNBOUND)
                result = tree.kind.toString();
            else
                result = tree.kind + " " + print(tree.inner);
        }

        private String result;
    }
}
