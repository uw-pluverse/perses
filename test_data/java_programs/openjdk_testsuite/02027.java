

import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic.Kind;

@SupportedAnnotationTypes("Anno")
public class AnnoProcessor extends JavacTestingAbstractProcessor {
    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public boolean process(Set<? extends TypeElement> set, RoundEnvironment re) {
        messager.printMessage(Kind.NOTE, "RUNNING - lastRound = " + re.processingOver());
        return true;
    }
}

