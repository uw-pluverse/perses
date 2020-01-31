



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

public class GetTypeElemBadArg extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> tes,
                           RoundEnvironment round) {
        if (round.processingOver()) return true;

        
        TypeElement te = elements.getTypeElement("Superless");
        tellAbout(te);

        te = elements.getTypeElement("Bo.o.o.gus");
        if (te != null) {
            tellAbout(te);
            throw new AssertionError();
        }
        return true;
    }

    private static void tellAbout(TypeElement t) {
        System.out.println(t);
        System.out.println(t.getClass());
        System.out.println(t.getKind());
        System.out.println();
    }
}
