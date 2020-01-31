

import java.lang.annotation.Repeatable;
import java.lang.annotation.Inherited;

@Inherited
@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer{
    Foo[] value();
}

@Foo @Foo
public class InheritedContainerAnno {}

