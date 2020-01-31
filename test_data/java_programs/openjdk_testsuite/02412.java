

import java.lang.annotation.*;



@Target({
    ElementType.TYPE_USE,
})
@interface Container {
  DefaultTargetTypeUse[] value();
}

@Repeatable(Container.class)
public @interface DefaultTargetTypeUse {}
