
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import static javax.tools.Diagnostic.Kind.*;

@Deprecated 
@SuppressWarnings({""})
public class T6362067 extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annos,
                           RoundEnvironment roundEnv) {

        for (Element e: roundEnv.getRootElements()) {
            messager.printMessage(NOTE, "note:elem", e);
            for (AnnotationMirror a: e.getAnnotationMirrors()) {
                messager.printMessage(NOTE, "note:anno", e, a);
                for (AnnotationValue v: a.getElementValues().values()) {
                    messager.printMessage(NOTE, "note:value", e, a, v);
                }
            }
        }

        if (roundEnv.processingOver())
            messager.printMessage(NOTE, "note:nopos");
        return true;
    }
}
