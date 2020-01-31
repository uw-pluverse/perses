

import java.lang.annotation.*;



@interface FooContainer {
  Foo[] value();
}

@Target({
    ElementType.CONSTRUCTOR,
    ElementType.PARAMETER,
    ElementType.TYPE,
    ElementType.METHOD,
    ElementType.LOCAL_VARIABLE,
    ElementType.PACKAGE,
    ElementType.ANNOTATION_TYPE,
    ElementType.FIELD,
})
@Repeatable(FooContainer.class)
@interface Foo {}

class NoTargetOnContainer {}
