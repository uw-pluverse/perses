



import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import java.util.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;

public class TestResourceElement extends JavacTestingAbstractProcessor implements AutoCloseable {
    public boolean process(Set<? extends TypeElement> annotations,
                          RoundEnvironment roundEnv) {
       if (!roundEnv.processingOver()) {
           Trees trees = Trees.instance(processingEnv);

           for(Element rootElement : roundEnv.getRootElements()) {
               TreePath treePath = trees.getPath(rootElement);

               VariableScanner varScanner =  new VariableScanner(trees);
               varScanner.scan(trees.getTree(rootElement),
                        treePath.getCompilationUnit());
               if (varScanner.getTrvElement() == null) {
                   throw new AssertionError("Element is null for 'trv'");
               }
           }
       }
       return true;
    }

    @Override
    public void close() {}

    private void test1() {
        
        
        try(TestResourceElement trv = this) {}
    }

    class VariableScanner extends TreeScanner<Void, CompilationUnitTree> {
       private Trees trees;
       private Element trvElement;

       public VariableScanner(Trees trees) {
           super();
           this.trees = trees;
       }
       @Override
       public Void visitVariable(VariableTree node, CompilationUnitTree cu) {
           
           if (node.getName().contentEquals("trv")) {
               trvElement = trees.getElement(trees.getPath(cu, node));
           }
           return super.visitVariable(node, cu);
       }

       Element getTrvElement() {
           return trvElement;
       }
   }
}
