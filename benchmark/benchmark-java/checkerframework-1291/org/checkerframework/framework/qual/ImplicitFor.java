package org.checkerframework.framework.qual;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import javax.lang.model.type.TypeKind;

@Retention(RetentionPolicy.RUNTIME)
@Target({ ElementType.ANNOTATION_TYPE })
public @interface ImplicitFor {

    LiteralKind[] literals() default {};

    TypeKind[] types() default {};

    Class<?>[] typeNames() default {};

    String[] stringPatterns() default {};
}
