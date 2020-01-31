

import java.lang.annotation.*;



class DefaultScope {
  void parameterized() {
    Parameterized<String, String> unannotated;
    Parameterized<@A String, String> firstTypeArg;
    Parameterized<String, @A String> secondTypeArg;
    Parameterized<@A String, @B String> bothTypeArgs;

    Parameterized<@A Parameterized<@A String, @B String>, @B String>
      nestedParameterized;
  }

  void arrays() {
    @A String [] array1;
    @A String @B [] array1Deep;
    @A String [] [] array2;
    @A String @A [] @B [] array2Deep;
    String @A [] [] array2First;
    String [] @B [] array2Second;
  }
}

class ModifiedVars {
  void parameterized() {
    final Parameterized<String, String> unannotated = null;
    final Parameterized<@A String, String> firstTypeArg = null;
    final Parameterized<String, @A String> secondTypeArg = null;
    final Parameterized<@A String, @B String> bothTypeArgs = null;

    final Parameterized<@A Parameterized<@A String, @B String>, @B String>
      nestedParameterized = null;
  }

  void arrays() {
    final @A String [] array1 = null;
    final @A String @B [] array1Deep = null;
    final @A String [] [] array2 = null;
    final @A String @A [] @B [] array2Deep = null;
    final String @A [] [] array2First = null;
    final String [] @B [] array2Second = null;
  }
}

class Parameterized<K, V> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
