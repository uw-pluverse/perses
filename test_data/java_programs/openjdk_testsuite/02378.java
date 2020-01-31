

import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {
    int getNumbers();
}

@interface FooContainer{
    Foo value();     
}

@Foo @Foo
public class WrongReturnTypeForValue {}
