



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import static javax.tools.Diagnostic.Kind.*;


public class TestTypeElement extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            for (Element element : roundEnv.getRootElements()) {
                if (element.getKind().isClass() || element.getKind().isInterface()) {
                    if (element.getModifiers().contains(Modifier.DEFAULT))
                        messager.printMessage(ERROR, "Modifier.DEFAULT not expected on classes/interfaces");
                }
            }
        }
        return true;
    }

}


interface InterfaceWithDefaultMethod {
    default void quux() {}
}
