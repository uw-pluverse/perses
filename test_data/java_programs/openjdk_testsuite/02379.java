



import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@interface Foos {
    SelfRepeatingAnno[] value();
}

@SelfRepeatingAnno
@Retention(RetentionPolicy.RUNTIME)
@SelfRepeatingAnno
@Repeatable(Foos.class)
@interface SelfRepeatingAnno {}

public class SelfRepeatingAnnotations {
    public static void  main(String[] args) throws Exception {
        Annotation a = SelfRepeatingAnno.class.getAnnotation(Foos.class);
        if (a == null) {
            throw new RuntimeException("Container annotation missing");
        }
    }
}
