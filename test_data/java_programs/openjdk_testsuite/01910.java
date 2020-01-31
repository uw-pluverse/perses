



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;


public class TestElement extends JavacTestingAbstractProcessor {
    
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            boolean hasRun = false;
            for (Element element : roundEnv.getRootElements()) {
                for (ExecutableElement ctor : constructorsIn(element.getEnclosedElements())) {
                    hasRun = true;
                    Name ctorName = ctor.getSimpleName();
                    if (!ctorName.contentEquals("<init>"))
                        throw new RuntimeException("Unexpected name for constructor " + ctorName);
                }
            }
            if (!hasRun)
                throw new RuntimeException("No constructors!");
        }
        return true;
    }
}
