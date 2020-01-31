

import java.lang.annotation.*;

public class TypeAnnotations extends @TA Object implements @TA Runnable {

    public @TA String @TA [] m(@TA String @TA [] p) throws @TA Throwable {
        Runnable r = () -> {
            @TA Object tested = null;
            @TA boolean isAnnotated = tested instanceof @TA String;
        };

        @TA Object tested = null;
        @TA boolean isAnnotated = tested instanceof @TA String;

        return (@TA String @TA []) null;
    }

    {
        Runnable r = () -> {
            @TA Object tested = null;
            @TA boolean isAnnotated = tested instanceof @TA String;
        };

        @TA Object tested = null;
        @TA boolean isAnnotated = tested instanceof @TA String;

        @TA String @TA [] ret = (@TA String @TA []) null;
    }

    @TA String @TA [] f = new @TA String @TA[0];

    @Override public void run() { }

    public static class Inner extends @TA Object implements @TA Runnable {
        @Override public void run() { }
    }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE})
@Deprecated
@interface TA {

}
