



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

import static javax.lang.model.util.ElementFilter.typesIn;

@HelloIm("BinaryName")
public class BinaryName extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> tes,
                           RoundEnvironment round) {
        if (round.processingOver()) return true;

        Set<? extends TypeElement> ts = typesIn(round.getElementsAnnotatedWith(
                elements.getTypeElement("HelloIm")));

        boolean success = true;
        for (TypeElement t : ts) {
            String expected = t.getAnnotation(HelloIm.class).value();
            CharSequence found = elements.getBinaryName(t);
            if (expected.contentEquals(found)) {
                System.out.println(expected + " == " + found);
            } else {
                success = false;
                System.out.println(expected + " != " + found + "  [FAIL]");
            }
        }
        if (! success)
            throw new AssertionError();
        return true;
    }

    @HelloIm("BinaryName$Nested")
    private static class Nested {
    }
}

@interface HelloIm {
    String value();
}
