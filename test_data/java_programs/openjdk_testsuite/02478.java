

import java.lang.annotation.*;


class TypeCasts {
  void methodA() {
    String s = (@A String) null;
    Object o = (@A Class<@A String>) null;
  }

  void methodB() {
    String s = (@B("m") String) null;
    Object o = (@B("m") Class<@B("m") String>) null;
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { String value(); }
