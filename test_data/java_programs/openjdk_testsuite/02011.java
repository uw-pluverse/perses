



import java.io.IOException;
import java.io.Writer;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.Filer;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.Elements;

@SupportedAnnotationTypes("TestMe")
public class T6413690 extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        TypeElement testMe = elements.getTypeElement(TestMe.class.getName());
        Set<? extends Element> supers = roundEnvironment.getElementsAnnotatedWith(testMe);
        try {
            for (Element sup : supers) {
                Writer sub = filer.createSourceFile(sup.getSimpleName() + "_GENERATED").openWriter();
                sub.write(String.format("class %s_GENERATED extends %s {}",
                                        sup.getSimpleName(),
                                        ((TypeElement)sup).getQualifiedName()));
                sub.close();
            }
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
        return true;
    }
}
