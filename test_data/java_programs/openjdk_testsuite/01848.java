



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;

@SupportedAnnotationTypes("IAm")
@IAm(OverEager.class)
public class OverEager extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annoTypes,
                           RoundEnvironment round) {
        if (!round.processingOver())
            doit(annoTypes, round);
        return true;
    }

    private void doit(Set<? extends TypeElement> annoTypes,
                      RoundEnvironment round) {
        for (TypeElement t : typesIn(round.getRootElements())) {
            IAm anno = t.getAnnotation(IAm.class);
            if (anno != null)
                checkAnno(anno);
        }
    }

    private void checkAnno(IAm anno) {
        try {
            anno.value();
            throw new AssertionError();
        } catch (MirroredTypeException e) {
            System.out.println("Looking for checkAnno in this stack trace:");
            e.printStackTrace();
            for (StackTraceElement frame : e.getStackTrace()) {
                if (frame.getMethodName() == "checkAnno")
                    return;
            }
            throw new AssertionError();
        }
    }
}

@interface IAm {
    Class<?> value();
}
