



import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {}

@interface FooContainer {
    Foo[] value();
    String other() default "other-method";
}

@Foo @Foo
public class DefaultCasePresent {}

