

import java.lang.annotation.*;


class VoidGenericMethod {
  public @A <T> void method() { }
}

@Target(ElementType.TYPE_USE)
@interface A { }
