

import java.io.IOException;
import java.io.Writer;
import java.lang.annotation.*;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.util.ElementFilter;
import javax.tools.*;
import com.sun.tools.javac.util.Assert;

public class Processor extends JavacTestingAbstractProcessor {

    private boolean seenGenerated;

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (Element e : roundEnv.getElementsAnnotatedWith(Gen.class)) {
            Gen gen = e.getAnnotation(Gen.class);
            try {
                JavaFileObject source = processingEnv.getFiler().createSourceFile(gen.fileName());

                try (Writer out = source.openWriter()) {
                    out.write(gen.content());
                }
            } catch (IOException ex) {
                throw new IllegalStateException(ex);
            }
        }

        TypeElement generated = processingEnv.getElementUtils().getTypeElement("Generated");

        if (generated != null) {
            Check check = ElementFilter.methodsIn(generated.getEnclosedElements()).get(0).getAnnotation(Check.class);

            checkCorrectException(check::classValue, "java.lang.Class<java.lang.String>");
            checkCorrectException(check::intConstValue, "boolean");
            checkCorrectException(check::enumValue, "java.lang.String");
            checkCorrectException(check::incorrectAnnotationValue, "java.lang.Deprecated");
            checkCorrectException(check::incorrectArrayValue, "<any>");
            checkCorrectException(check::incorrectClassValue, "<any>");

            seenGenerated = true;
        }

        if (roundEnv.processingOver() && !seenGenerated) {
            Assert.error("Did not see the generated class!");
        }

        return true;
    }

    private static void checkCorrectException(Runnable runCheck, String expectedType) {
        try {
            runCheck.run();
            Assert.check(false); 
        } catch (AnnotationTypeMismatchException ex) {
            Assert.check(expectedType.equals(ex.foundType()), ex.foundType());
        }
    }

}

@interface Gen {
    String fileName();
    String content();
}

@interface Check {
    Class<? extends Number> classValue();
    int intConstValue();
    E enumValue();
    int incorrectAnnotationValue();
    int incorrectArrayValue();
    Class<?> incorrectClassValue();
}

enum E {
    A;
}
