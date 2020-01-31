

import java.lang.annotation.*;



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
@interface Container {
  DefaultTarget[] value();
}

@Repeatable(Container.class)
public @interface DefaultTarget {}
