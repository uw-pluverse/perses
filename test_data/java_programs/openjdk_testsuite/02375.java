

import java.lang.annotation.Repeatable;

@Repeatable()
@interface Foo {}

@interface FooContainer {
    Foo[] value();
}

@Foo @Foo
public class MissingContainer {}
