

import java.lang.annotation.*;



class Unannotated<K> { }
class OneAnnotated<@A K> { }
class TwoAnnotated<@A K, @A V> { }
class SecondAnnotated<K, @A V extends String> { }

class TestMethods {
  <K> void unannotated() { }
  <@A K> void oneAnnotated() { }
  <@A K, @B("m") V> void twoAnnotated() { }
  <K, @A V extends @A String> void secondAnnotated() { }
}

class UnannotatedB<K> { }
class OneAnnotatedB<@B("m") K> { }
class TwoAnnotatedB<@B("m") K, @B("m") V> { }
class SecondAnnotatedB<K, @B("m") V extends @B("m") String> { }

class OneAnnotatedC<@C K> { }
class TwoAnnotatedC<@C K, @C V> { }
class SecondAnnotatedC<K, @C V extends String> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { String value(); }
@Target(ElementType.TYPE_USE)
@interface C { }
