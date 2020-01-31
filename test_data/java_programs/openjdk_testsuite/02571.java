
import java.lang.annotation.*;
class DuplicateAnnotationValue {
  void test() {
    String[] a = new String @A(value = 2, value = 1) [5] ;
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { int value(); }
