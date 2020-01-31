

import java.lang.annotation.*;



class Parameters {
  void unannotated(Parameterized<String, String> a) {}
  void firstTypeArg(Parameterized<@A String, String> a) {}
  void secondTypeArg(Parameterized<String, @A String> a) {}
  void bothTypeArgs(Parameterized<@A String, @B String> both) {}

  void nestedParameterized(Parameterized<@A Parameterized<@A String, @B String>, @B String> a) {}

  void array1(@A String [] a) {}
  void array1Deep(@A String @B [] a) {}
  void array2(@A String [] [] a) {}
  void array2Deep(@A String @A [] @B [] a) {}
  void array2First(String @A [] [] a) {}
  void array2Second(String [] @B [] a) {}
}

class Parameterized<K, V> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
