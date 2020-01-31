

import java.lang.annotation.ElementType;
import java.lang.annotation.Target;



public class QualifiedName {
    @Target(ElementType.TYPE_USE) @interface TA { }
    class E extends Exception { }

    void m() throws @TA QualifiedName.@TA E { }
}
