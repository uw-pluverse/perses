



import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

@A
class TypeUseTarget<K extends @A Object> {
  @A String @A [] field;

  @A String test(@A TypeUseTarget<K> this, @A String param, @A String @A ... vararg) {
    @A Object o = new @A String @A [3];
    TypeUseTarget<@A String> target;
    return (@A String) null;
  }

  <K> @A String genericMethod(K k) { return null; }
  @Decl <K> @A String genericMethod1(K k) { return null; }
  @A @Decl <K> String genericMethod2(K k) { return null; }
  @Decl @A <K> String genericMethod3(K k) { return null; }
  <K> @Decl String genericMethod4(K k) { return null; }
  <K> @A @Decl String genericMethod5(K k) { return null; }
}

@A
interface MyInterface { }

@A
@interface MyAnnotation { }

@Target(ElementType.TYPE_USE)
@interface A { }

@interface Decl { }
