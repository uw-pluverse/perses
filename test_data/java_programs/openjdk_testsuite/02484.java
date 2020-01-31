

import java.lang.annotation.*;



class UnscopedUnmodified {
  <K extends @A String> void methodExtends() {}
  <K extends @A Parameterized<@B String>> void nestedExtends() {}
  <K extends @A String, V extends @A Parameterized<@B String>> void dual() {}
  <K extends String, V extends Parameterized<@B String>> void dualOneAnno() {}
}

class PublicModifiedMethods {
  public final <K extends @A String> void methodExtends() {}
  public final <K extends @A Parameterized<@B String>> void nestedExtends() {}
  public final <K extends @A String, V extends @A Parameterized<@B String>> void dual() {}
  public final <K extends String, V extends Parameterized<@B String>> void dualOneAnno() {}
}

class Parameterized<K> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
