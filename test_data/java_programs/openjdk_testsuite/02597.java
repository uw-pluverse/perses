



import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

class TypeUseTarget<@A K extends Object> {
  String[] field;

  <@A K, @A V> String genericMethod(K k) { return null; }
}

interface MyInterface { }

@interface MyAnnotation { }

@Target(ElementType.TYPE_PARAMETER)
@interface A { }
