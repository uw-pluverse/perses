
import java.lang.annotation.*;
class DuplicateTypeAnno<@A @A K> {
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
