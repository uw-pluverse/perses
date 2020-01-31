
import java.lang.annotation.*;
class DuplicateAnnotationValue {
  void test() {
    String @A(value = 2, value = 1) [] s;
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { int value(); }
