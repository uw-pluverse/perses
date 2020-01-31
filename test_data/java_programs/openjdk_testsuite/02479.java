

import java.lang.annotation.*;



class DefaultScope {
  Parameterized<String, String> unannotated;
  Parameterized<@A String, String> firstTypeArg;
  Parameterized<String, @A String> secondTypeArg;
  Parameterized<@A String, @B String> bothTypeArgs;

  Parameterized<@A Parameterized<@A String, @B String>, @B String>
    nestedParameterized;

  @A String [] array1;
  @A String @B [] array1Deep;
  @A String [] [] array2;
  @A String @A [] @B [] array2Deep;
  String @A [] [] array2First;
  String [] @B [] array2Second;

  
  String array2FirstOld @A [];
  String array2SecondOld [] @B [];
}

class ModifiedScoped {
  public final Parameterized<String, String> unannotated = null;
  public final Parameterized<@A String, String> firstTypeArg = null;
  public final Parameterized<String, @A String> secondTypeArg = null;
  public final Parameterized<@A String, @B String> bothTypeArgs = null;

  public final Parameterized<@A Parameterized<@A String, @B String>, @B String>
    nestedParameterized = null;

  public final @A String [] array1 = null;
  public final @A String @B [] array1Deep = null;
  public final @A String [] [] array2 = null;
  public final @A String @A [] @B [] array2Deep = null;
  public final String @A [] [] array2First = null;
  public final String [] @B [] array2Second = null;
}

class Parameterized<K, V> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
