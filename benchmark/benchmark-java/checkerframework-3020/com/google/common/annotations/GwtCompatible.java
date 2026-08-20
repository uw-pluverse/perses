package com.google.common.annotations;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.CLASS)
@Documented
@GwtCompatible
@Target({ ElementType.TYPE })
public @interface GwtCompatible {

    boolean serializable() default false;

    boolean emulated() default false;
}
