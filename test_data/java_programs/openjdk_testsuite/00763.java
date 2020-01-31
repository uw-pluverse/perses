



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;

import com.sun.source.tree.*;
import com.sun.source.util.Trees;

@SupportedAnnotationTypes("*")
public class TestGetTree extends AbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment)
    {
        final Trees trees = Trees.instance(processingEnv);
        for (TypeElement e : typesIn(roundEnvironment.getRootElements())) {
            ClassTree node = trees.getTree(e);
            System.out.println(node.toString());
        }
        return true;
    }
}
