

import java.lang.annotation.*;
import static java.lang.annotation.ElementType.*;


@Target({TYPE_USE, TYPE_PARAMETER})
@interface TA {
    String value();
}

