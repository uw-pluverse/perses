



import java.util.*;

import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;

import com.sun.source.tree.*;
import com.sun.source.util.*;

@SupportedAnnotationTypes("*")
public class T6855236 extends AbstractProcessor {

    private Trees trees;

    @Override
    public void init(ProcessingEnvironment pe) {
        super.init(pe);
        trees = Trees.instance(pe);
    }

    @Override
    public boolean process(Set<? extends TypeElement> arg0, RoundEnvironment roundEnvironment) {
        
        CodeVisitor visitor = new CodeVisitor();

        for (Element e : roundEnvironment.getRootElements()) {
            TreePath tp = trees.getPath(e);
            visitor.scan(tp, trees);
        }

        return true;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    class CodeVisitor extends TreePathScanner<Object, Trees> {

        @Override
        public Object visitMethodInvocation(MethodInvocationTree node, Trees p) {
            System.out.println("current path: ");
            for (Tree t : getCurrentPath()) {
                System.out.println("    " + t.getKind() + ": " + trim(t, 64));
            }
            System.out.println("parent path: " + getCurrentPath().getParentPath());
            System.out.println("method select: " + node.getMethodSelect().toString());
            for (ExpressionTree arg : node.getArguments()) {
                System.out.println("argument: " + arg.toString());
            }
            return super.visitMethodInvocation(node, p);
        }

        @Override
        public Object visitExpressionStatement(ExpressionStatementTree node, Trees p) {
            ExpressionTree t = node.getExpression();
            System.out.println();
            System.out.println("expression statement: " + trim(t, 64));
            return super.visitExpressionStatement(node, p);
        }

    }

    private String trim(Tree t, int len) {
        String s = t.toString().trim().replaceAll("\\s+", " ");
        if (s.length() > len)
            s = s.substring(0, len) + "...";
        return s;
    }

}


