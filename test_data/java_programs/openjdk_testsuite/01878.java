

import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface ExpectedBase {
    Class<? extends Annotation> value() default Annotation.class;
    String getAnnotation() default "";
    String[] getAllAnnotationMirrors() default {};
    String[] getAnnotationMirrors() default {};
    
    String[] getAnnotationsByType() default {};
}
