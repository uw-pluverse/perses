

import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer {
    Foo[] value();
    Foo other();  
}

@Foo @Foo
public class MissingDefaultCase2 {}
