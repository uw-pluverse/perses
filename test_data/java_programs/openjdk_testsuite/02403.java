

package expectedFiles;
import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
@Retention(RetentionPolicy.RUNTIME)
public @interface ExpectedBase {
    Class<? extends Annotation> value() default Annotation.class;
    String getAnnotationVal() default "";
    String[] getAnnotationsVals() default {};
    String[] getDeclAnnosVals() default {};
    
    String getDeclAnnoVal() default "";
    String[] getAnnosArgs() default{};
    String[] getDeclAnnosArgs() default {};
}

