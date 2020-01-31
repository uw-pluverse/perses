

import java.lang.annotation.*;



class DefaultScope {
  void exception01() {
    try {
        System.out.println("Hello 1!");
    } catch (@B NullPointerException | @C IllegalArgumentException e) {
      e.toString();
    }
  }
  
}

class ModifiedVars {
  void exception01() {
    try {
        System.out.println("Hello 1!");
    } catch (final @B NullPointerException | @C IllegalArgumentException e) {
      e.toString();
    }
  }
  void exception02() {
    try {
        System.out.println("Hello 1!");
    } catch (@Decl @B NullPointerException | @C IllegalArgumentException e) {
      e.toString();
    }
  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface C { }

@interface Decl { }
