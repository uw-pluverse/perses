

import com.sun.tools.javac.util.Assert;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@SupportedAnnotationTypes("*")
public class GenerateSuperInterfaceProcessor extends AbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (Element el : roundEnv.getElementsAnnotatedWith(Generate.class)) {
            Generate g = el.getAnnotation(Generate.class);

            Assert.checkNonNull(g);

            try (OutputStream out =
                    processingEnv.getFiler().createSourceFile(g.fileName()).openOutputStream()) {
                out.write(g.content().getBytes());
            } catch (IOException ex) {
                throw new IllegalStateException(ex);
            }
        }

        return false;
    }

}

@interface Generate {
    String fileName();
    String content();
}
