



import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Foos.class)
@interface Foo {}

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(FoosFoos.class)
@interface Foos {
    Foo[] value();
}

@Retention(RetentionPolicy.RUNTIME)
@interface FoosFoos {
    Foos[] value();
}

@Foo
@Foo
class BasicRepeatingAnnos {}

@Foos({})
@Foos({})
class BasicRepeatingAnnos2 {}

public class NestedContainers {
    public static void main(String[] args) throws Exception {
        Annotation a = BasicRepeatingAnnos.class.getAnnotation(Foos.class);
        if (a == null) {
            throw new RuntimeException("Container annotation missing");
        }

        
        a = BasicRepeatingAnnos2.class.getAnnotation(FoosFoos.class);
        if (a == null) {
            throw new RuntimeException("Container annotation missing");
        }
    }
}
