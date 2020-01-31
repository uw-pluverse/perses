



import java.lang.annotation.Repeatable;

@Repeatable(FooContainer.class)
@interface Foo {
    int getNumbers();
}

@interface FooContainer {
  Foo[] value();
}

@Repeatable(BazContainer.class)
@interface Baz {
    String getStr();
}

@interface BazContainer {
  Baz[] value();
}

@Foo(getNumbers=1)
@Baz(getStr="hello")
@Foo(getNumbers=2)
@Baz(getStr="world")
public class MultipleAnnoMixedOrder  {}

