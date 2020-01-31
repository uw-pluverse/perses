



package cycle3;

import java.lang.annotation.Retention;
import static java.lang.annotation.RetentionPolicy.*;

@Retention(RUNTIME)
@interface A {
    A[] values() default { @A() };
}

@A()
class Main {
    public static void main(String[] args) {
        A a = Main.class.getAnnotation(A.class);
        System.out.println(a);
    }
}
