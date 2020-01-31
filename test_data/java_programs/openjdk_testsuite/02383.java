

import java.lang.annotation.*;

public class TypeUseTargetNeg {}


@Target({
    ElementType.TYPE_USE,
})
@Repeatable(FooContainer.class)
@interface Foo {}

@Target({
    ElementType.ANNOTATION_TYPE,
    ElementType.TYPE,
    ElementType.TYPE_USE,
    ElementType.TYPE_PARAMETER,
    ElementType.FIELD,

})
@interface FooContainer {
  Foo[] value();
}



@Target({
    ElementType.TYPE_USE,
})
@Repeatable(BarContainer.class)
@interface Bar {}

@Target({
    ElementType.ANNOTATION_TYPE,
    ElementType.TYPE,
    ElementType.TYPE_USE,
    ElementType.METHOD,
})
@interface BarContainer {
  Bar[] value();
}



@Target({
    ElementType.TYPE_USE,
})
@Repeatable(BazContainer.class)
@interface Baz {}

@Target({
    ElementType.ANNOTATION_TYPE,
    ElementType.TYPE,
    ElementType.PARAMETER,
})
@interface BazContainer {
  Baz[] value();
}



@Target({
    ElementType.TYPE_USE,
})
@Repeatable(QuxContainer.class)
@interface Qux {}

@interface QuxContainer {
  Qux[] value();
}



@Target({})
@Repeatable(QuuxContainer.class)
@interface Quux {}

@Target({
    ElementType.TYPE_PARAMETER,
})
@interface QuuxContainer {
  Quux[] value();
}


@Repeatable(QuuuxContainer.class)
@interface Quuux {}

@Target({
    ElementType.TYPE_USE,
})
@interface QuuuxContainer {
  Quuux[] value();
}
