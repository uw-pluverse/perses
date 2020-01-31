
import java.lang.annotation.*;
class DuplicateAnnotationValue {
  void test() {
    new @A String();
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { int field(); }
