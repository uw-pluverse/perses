

import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;

@Retention(RUNTIME)
@Target(ElementType.TYPE_PARAMETER)
public @interface TpAnno {}
