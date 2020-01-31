

import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;


@Retention(RUNTIME)
public @interface AnnotatedElementInfo {
    String annotationName();
    int expectedSize();
    String[] names();
}
