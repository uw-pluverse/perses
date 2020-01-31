
import java.lang.annotation.*;
class DuplicateTypeAnnotation {
  void test() {
    new @A @A String();
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
