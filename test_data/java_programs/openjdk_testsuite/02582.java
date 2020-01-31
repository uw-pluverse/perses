

import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

class Constructor {
  
  @A Constructor() { }

  
  @B Constructor(int x) { }

  
  

  
}

class Constructor2 {
  class Inner {
    
    @A Inner() { }
  }
}

@Target(ElementType.TYPE_USE)
@interface A { }

@Target(ElementType.TYPE_PARAMETER)
@interface B { }

