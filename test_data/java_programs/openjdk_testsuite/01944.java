

import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;

@Retention(RUNTIME)
public @interface ExpectedElementCounts {
    int constructors() default 1;
    int fields()       default 0;
    int methods()      default 0;
    int types()        default 0;
}
