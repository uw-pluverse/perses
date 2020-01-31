
import java.lang.annotation.*;
class DuplicateTypeAnno<K extends @A @A Object> {
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
