
import java.lang.annotation.*;
class DuplicateTypeAnno {
  void innermethod() {
    class Inner<@A @A K> { }
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
