

import java.lang.annotation.*;



class MethodTypeArgs {
  void oneArg() {
    this.<@A String>newList();
    this.<@A MyList<@B(0) String>>newList();

    MethodTypeArgs.<@A String>newList();
    MethodTypeArgs.<@A MyList<@B(0) String>>newList();
  }

  void twoArg() {
    this.<String, String>newMap();
    this.<@A String, @B(0) MyList<@A String>>newMap();

    MethodTypeArgs.<String, String>newMap();
    MethodTypeArgs.<@A String, @B(0) MyList<@A String>>newMap();
  }

  void withArraysIn() {
    this.<String[]>newList();
    this.<@A String @B(0) [] @A []>newList();

    this.<@A String[], @B(0) MyList<@A String> @A []>newMap();
  }

  static <E> void newList() { }
  static <K, V> void newMap() { }
}

class MyList<E> { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { int value(); }
