
import java.lang.annotation.*;
class DuplicateAnnotationValue<K> {
  DuplicateAnnotationValue<@A(value = 2, value = 1) String> l;
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { int value(); }
