

import java.lang.annotation.*;
import static java.lang.annotation.ElementType.*;


@Target({FIELD, LOCAL_VARIABLE, METHOD, PACKAGE, PARAMETER, TYPE})
@interface DA {
    String value();
}

