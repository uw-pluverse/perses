


import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

public class T8011722 {
    class InnerException extends Exception { }
    void foo() throws @C T8011722.@C InnerException {    }
}

@Target(ElementType.TYPE_USE) @interface C { }
