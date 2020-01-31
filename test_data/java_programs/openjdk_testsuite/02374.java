

import java.lang.annotation.*;



@Target({
    ElementType.TYPE_PARAMETER,
})
@interface Container {
  DefaultTargetTypeParameter[] value();
}

@Repeatable(Container.class)
public @interface DefaultTargetTypeParameter {}
