
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target(ElementType.ANNOTATION_TYPE)
@interface Pos {
    long line() default -1;
    long col() default -1;
    boolean userDefined() default true;
}
