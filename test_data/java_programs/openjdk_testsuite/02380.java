



import java.lang.annotation.*;

@Repeatable(Foos.class)
@interface Foo {}

@interface Foos {
    Foo[] value();
}


@Foo
@Foo
@Foos({})
public class RepeatingAndContainerPresent {}
