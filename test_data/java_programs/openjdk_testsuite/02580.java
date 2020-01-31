

import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

class VoidMethod {
  @A void test() { }
}

@Target(ElementType.TYPE)
@interface A { }
