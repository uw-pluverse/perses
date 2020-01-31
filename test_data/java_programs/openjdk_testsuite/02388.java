


import java.lang.annotation.Repeatable;

public class ClassReaderDefault {
}

@interface FooContainer {
     Foo[] value();
     int f() default 0;
}

@Repeatable(FooContainer.class)
@interface Foo {}
