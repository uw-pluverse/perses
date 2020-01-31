
import java.lang.annotation.*;
class DuplicateAnnotationValue<K extends @A(value = 2, value = 1) Object> {
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { int value(); }
