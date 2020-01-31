



import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;
import java.io.Writer;


public class TestDeprecation extends JavacTestingAbstractProcessor {

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        boolean failure = false;
        if (!roundEnv.processingOver()) {
            DeprecationChecker deprecationChecker = new DeprecationChecker();

            for(Element element: roundEnv.getRootElements() ) {
                System.out.println("\nRoot Element: " + element.getSimpleName());
                failure = deprecationChecker.scan(element);
            }

            if (failure)
                processingEnv.getMessager().printMessage(ERROR, "Deprecation mismatch found!");
        }
        return true;
    }

    private class DeprecationChecker extends ElementScanner<Boolean,Void> {
        private Elements elementUtils;
        private boolean failure;
        DeprecationChecker() {
            super(false);
            elementUtils = processingEnv.getElementUtils();
            failure = false;
        }

        @Override
        public Boolean scan(Element e, Void p) {
            boolean expectedDeprecation = false;
            ExpectedDeprecation tmp = e.getAnnotation(ExpectedDeprecation.class);
            if (tmp != null)
                expectedDeprecation = tmp.value();
            boolean actualDeprecation = elementUtils.isDeprecated(e);

            System.out.printf("\tVisiting %s\t%s%n", e.getKind(), e.getSimpleName());

            if (expectedDeprecation != actualDeprecation) {
                failure = true;
                java.io.StringWriter w = new java.io.StringWriter();
                elementUtils.printElements(w, e);
                System.out.printf("For the deprecation of %n\t%s\t, expected %b, got %b.%n",
                                  w.getBuffer().toString(),
                                  expectedDeprecation, actualDeprecation);
            }
            super.scan(e, p);
            return failure;
        }
    }
}
