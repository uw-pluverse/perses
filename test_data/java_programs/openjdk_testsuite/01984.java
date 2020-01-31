



import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;


@SupportedAnnotationTypes("*")
@SupportedOptions("SourceVersion")
public class TestSourceVersionWarnings extends AbstractProcessor {

    @Override
    public SourceVersion getSupportedSourceVersion() {
        String sourceVersion = processingEnv.getOptions().get("SourceVersion");
        if (sourceVersion == null) {
            processingEnv.getMessager().printMessage(WARNING,
                                                     "No SourceVersion option given");
            return SourceVersion.RELEASE_6;
        } else {
            return SourceVersion.valueOf(sourceVersion);
        }
    }

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        return true;
    }
}
