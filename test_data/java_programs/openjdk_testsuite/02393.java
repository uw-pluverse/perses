



import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Foos.class)
@interface Foo {}

@Retention(RetentionPolicy.RUNTIME)
@interface Foos {
    Foo[] value();
}

@interface Bar {}

@Foo @Foo
@Foo
@Bar
@Foo
@Foo
@Foo
@Foo
@Foo @Foo
@Foo
class BasicRepeatingAnnos {}

@Foo
class BasicNonRepeatingAnno {}

public class BasicRepeatingAnnotations {
    public static void main(String[] args) throws Exception {
        Annotation a = BasicRepeatingAnnos.class.getAnnotation(Foos.class);
        if (a == null) {
            throw new RuntimeException("Container annotation missing");
        }

        
        a = BasicNonRepeatingAnno.class.getAnnotation(Foos.class);
        if (a != null) {
            throw new RuntimeException("Container annotation present");
        }
        a = BasicNonRepeatingAnno.class.getAnnotation(Foo.class);
        if (a == null) {
            throw new RuntimeException("Repeated annoation not directly present");
        }
    }
}
