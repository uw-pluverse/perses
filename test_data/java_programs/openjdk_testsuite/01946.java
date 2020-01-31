



import javax.lang.model.UnknownEntityException;
import javax.lang.model.element.*;
import javax.lang.model.type.*;


public class TestExceptions {
    public static void main(String... args) {
        RuntimeException[] exceptions = {
            new UnknownElementException((Element)null, (Object)null),
            new UnknownAnnotationValueException((AnnotationValue) null, (Object) null),
            new UnknownTypeException((TypeMirror)null, (Object)null)
        };

        for(RuntimeException exception : exceptions) {
            try {
                throw exception;
            } catch (UnknownEntityException uee) {
                ;
            }
        }
    }
}
