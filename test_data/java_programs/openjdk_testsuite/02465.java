



import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

class TypeUseTarget<K extends @A Object> {
  @A void voidMethod() { }
}

@Target({ElementType.TYPE_USE, ElementType.METHOD})
@interface A { }
