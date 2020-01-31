



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;

@SupportedAnnotationTypes("*")
public class T6411379 extends AbstractProcessor {

    public boolean process(Set<? extends TypeElement> annoElems,
                                    RoundEnvironment renv) {
        Trees trees = Trees.instance(processingEnv);
        for (TypeElement annoElem: annoElems) {
            for (Element te: renv.getRootElements()) {
                System.err.println("te: " + te);
                for (AnnotationMirror anno: te.getAnnotationMirrors()) {
                    
                    
                    
                    checkNull(trees.getPath(annoElem, anno));
                    checkNull(trees.getTree(annoElem, anno));
                }
            }
        }
        return true;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    public void checkNull(Object o) {
        if (o != null)
            throw new AssertionError("expected null");
    }
}
