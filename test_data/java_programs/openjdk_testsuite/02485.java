

import java.lang.annotation.*;



class DefaultScope {
  Parameterized<String, String> unannotated() { return null; }
  Parameterized<@A String, String> firstTypeArg() { return null; }
  Parameterized<String, @A String> secondTypeArg() { return null; }
  Parameterized<@A String, @B String> bothTypeArgs() { return null; }

  Parameterized<@A Parameterized<@A String, @B String>, @B String>
    nestedParameterized() { return null; }

  public <T> @A String method() { return null; }

  @A String [] array1() { return null; }
  @A String @B [] array1Deep() { return null; }
  @A String [] [] array2() { return null; }
  @A String @A [] @B [] array2Deep() { return null; }
  String @A [] [] array2First() { return null; }
  String [] @B [] array2Second() { return null; }

  
  String array2FirstOld() @A [] { return null; }
  String array2SecondOld() [] @B [] { return null; }
}

class ModifiedScoped {
  public final Parameterized<String, String> unannotated() { return null; }
  public final Parameterized<@A String, String> firstTypeArg() { return null; }
  public final Parameterized<String, @A String> secondTypeArg() { return null; }
  public final Parameterized<@A String, @B String> bothTypeArgs() { return null; }

  public final Parameterized<@A Parameterized<@A String, @B String>, @B String>
    nestedParameterized() { return null; }

  public final @A String [] array1() { return null; }
  public final @A String @B [] array1Deep() { return null; }
  public final @A String [] [] array2() { return null; }
  public final @A String @A [] @B [] array2Deep() { return null; }
  public final String @A [] [] array2First() { return null; }
  public final String [] @B [] array2Second() { return null; }
}

class Parameterized<K, V> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
