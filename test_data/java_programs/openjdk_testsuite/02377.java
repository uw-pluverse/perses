



import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {}

@Repeatable(FooContainerContainer.class)
@interface FooContainer {
    Foo[] value();
}

@interface FooContainerContainer {
  FooContainer[] value();
}

@Foo @Foo
public class MultiLevelRepeatableAnno  {}

