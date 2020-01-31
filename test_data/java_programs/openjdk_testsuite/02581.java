

import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

class VoidMethod {
  
  @A void test1() { }
  
  @B void test2() { }
  
  @C void test3() { }
  
  @D void test4() { }
}

@Target(ElementType.TYPE_USE)
@interface A { }

@Target({ElementType.TYPE_USE, ElementType.METHOD})
@interface B { }

@Target(ElementType.TYPE_PARAMETER)
@interface C { }

@Target({ElementType.TYPE_PARAMETER, ElementType.METHOD})
@interface D { }
