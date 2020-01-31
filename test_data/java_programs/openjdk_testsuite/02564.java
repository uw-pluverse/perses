
import java.lang.annotation.*;
class DuplicateTypeAnno<K> {
  DuplicateTypeAnno<@A @A ?> l;
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
