

import java.lang.annotation.Repeatable;
import java.lang.annotation.Documented;

@Documented
@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer{
    Foo[] value();
}

@Foo @Foo
public class DocumentedContainerAnno {}
