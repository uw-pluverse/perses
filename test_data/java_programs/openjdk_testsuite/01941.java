



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;

public class DirectSupersOfErr extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> tes,
                           RoundEnvironment round) {
        if (round.processingOver()) return true;

        for (TypeElement te : typesIn(round.getRootElements())) {
            TypeMirror sup = te.getSuperclass();
            for (TypeMirror supOfSup : types.directSupertypes(sup)) {
                if (sup == supOfSup)
                    throw new AssertionError("I'm my own supertype.");
            }
        }
        return true;
    }
}
