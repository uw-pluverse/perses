
import java.lang.annotation.*;
class DuplicateTypeAnnotation {
  void test() {
    String[] a = new String @A @A [5] ;
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
