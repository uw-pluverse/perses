

import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer {
    Foo[] value();
    String other();  
}

@Foo @Foo
public class MissingDefaultCase1 {}
