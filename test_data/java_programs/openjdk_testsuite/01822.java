



import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;


@SupportedOptions("ExpectedVersion")
public class TestSourceVersion extends JavacTestingAbstractProcessor {

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        SourceVersion expectedVersion =
            SourceVersion.valueOf(processingEnv.getOptions().get("ExpectedVersion"));
        SourceVersion actualVersion =  processingEnv.getSourceVersion();
        System.out.println("Expected SourceVersion " + expectedVersion +
                           " actual SourceVersion "  + actualVersion);
        if (expectedVersion != actualVersion)
            throw new RuntimeException();

        return true;
    }
}
