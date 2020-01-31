



import java.lang.annotation.*;

@Repeatable(Foos.class)
@Target(ElementType.ANNOTATION_TYPE)
@interface Foo {}

@Target(ElementType.TYPE)
@interface Foos {
    Foo[] value();
}

public class InvalidTargets {}
