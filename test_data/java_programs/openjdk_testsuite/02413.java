

import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer{
    Foo[] values();  
}

@Foo @Foo
public class MissingValueMethod {}

