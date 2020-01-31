



import java.io.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;
import java.util.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import static javax.tools.Diagnostic.Kind.*;


public class TestResourceVariable extends JavacTestingAbstractProcessor implements AutoCloseable {
    int resourceVariableCount = 0;

    public boolean process(Set<? extends TypeElement> annotations,
                          RoundEnvironment roundEnv) {
       if (!roundEnv.processingOver()) {
           Trees trees = Trees.instance(processingEnv);

           for(Element rootElement : roundEnv.getRootElements()) {
               TreePath treePath = trees.getPath(rootElement);

               (new ResourceVariableScanner(trees)).
                   scan(trees.getTree(rootElement),
                        treePath.getCompilationUnit());
           }
           if (resourceVariableCount != 3)
               throw new RuntimeException("Bad resource variable count " +
                                          resourceVariableCount);
       }
       return true;
    }

    @Override
    public void close() {}

    private void test1() {
        try(TestResourceVariable trv = this) {}
    }

    private void test2() {
        try(TestResourceVariable trv1 = this; TestResourceVariable trv2 = trv1) {}
    }

    
    private static void testResourceVariable(Element element) {
        ElementVisitor visitor6 = new ElementKindVisitor6<Void, Void>() {};

        try {
            visitor6.visit(element);
            throw new RuntimeException("Expected UnknownElementException not thrown.");
        } catch (UnknownElementException uee) {
            ; 
        }

        ElementKindVisitor visitorLatest =
            new ElementKindVisitor<Object, Void>() {
            @Override
            public Object visitVariableAsResourceVariable(VariableElement e,
                                                          Void p) {
                return e; 
            }
        };

        if (visitorLatest.visit(element) == null) {
            throw new RuntimeException("Null result of resource variable visitation.");
        }
    }

    class ResourceVariableScanner extends TreeScanner<Void, CompilationUnitTree> {
       private Trees trees;

       public ResourceVariableScanner(Trees trees) {
           super();
           this.trees = trees;
       }
       @Override
       public Void visitVariable(VariableTree node, CompilationUnitTree cu) {
           Element element = trees.getElement(trees.getPath(cu, node));

           System.out.println("Name: " + element.getSimpleName() +
                              "\tKind: " + element.getKind());
           if (element.getKind() == ElementKind.RESOURCE_VARIABLE) {
               testResourceVariable(element);
               resourceVariableCount++;
           }
           return super.visitVariable(node, cu);
       }
    }
}
