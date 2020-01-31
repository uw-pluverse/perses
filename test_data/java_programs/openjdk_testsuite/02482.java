

import java.lang.annotation.*;


class BoundTest {
  void wcExtends(MyList<? extends @A String> l) { }
  void wcSuper(MyList<? super @A String> l) { }

  MyList<? extends @A String> returnWcExtends() { return null; }
  MyList<? super @A String> returnWcSuper() { return null; }
  MyList<? extends @A MyList<? super @B("m") String>> complex() { return null; }
}

class BoundWithValue {
  void wcExtends(MyList<? extends @B("m") String> l) { }
  void wcSuper(MyList<? super @B(value="m") String> l) { }

  MyList<? extends @B("m") String> returnWcExtends() { return null; }
  MyList<? super @B(value="m") String> returnWcSuper() { return null; }
  MyList<? extends @B("m") MyList<? super @B("m") String>> complex() { return null; }
}

class SelfTest {
  void wcExtends(MyList<@A ?> l) { }
  void wcSuper(MyList<@A ?> l) { }

  MyList<@A ?> returnWcExtends() { return null; }
  MyList<@A ?> returnWcSuper() { return null; }
  MyList<@A ? extends @A MyList<@B("m") ?>> complex() { return null; }
}

class SelfWithValue {
  void wcExtends(MyList<@B("m") ?> l) { }
  void wcSuper(MyList<@B(value="m") ?> l) { }

  MyList<@B("m") ?> returnWcExtends() { return null; }
  MyList<@B(value="m") ?> returnWcSuper() { return null; }
  MyList<@B("m") ? extends MyList<@B("m") ? super String>> complex() { return null; }
}

class MyList<K> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { String value(); }
