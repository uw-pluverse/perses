
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target(ElementType.TYPE)
@interface TraceResolve {
    String[] keys() default {};
}
