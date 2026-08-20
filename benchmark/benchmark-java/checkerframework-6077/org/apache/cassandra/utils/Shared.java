package org.apache.cassandra.utils;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
@Target({ ElementType.TYPE })
public @interface Shared {

    enum Scope {

        ANY, SIMULATION
    }

    enum Recursive {

        NONE
    }

    Scope[] scope() default Scope.ANY;

    Recursive inner() default Recursive.NONE;

    Recursive ancestors() default Recursive.NONE;

    Recursive members() default Recursive.NONE;
}
