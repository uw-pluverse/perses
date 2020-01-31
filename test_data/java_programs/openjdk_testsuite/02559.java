
import java.lang.annotation.*;
class DuplicateTypeAnnotation {
  void test() {
    String @A @A [] s;
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
