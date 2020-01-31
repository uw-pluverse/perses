

import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface ExpectedContainer {
    Class<? extends Annotation> value() default Annotation.class;
    String getAnnotation() default "";
    
    String[] getAnnotationsByType() default {};
    }
