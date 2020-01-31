

import java.lang.annotation.*;


abstract class MyClass extends @A ParameterizedClass<@B String>
  implements @B CharSequence, @A ParameterizedInterface<@B String> { }

interface MyInterface extends @A ParameterizedInterface<@A String>,
                              @B CharSequence { }

class ParameterizedClass<K> {}
interface ParameterizedInterface<K> {}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A {}
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B {}
