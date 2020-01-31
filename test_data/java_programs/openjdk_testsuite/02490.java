

import java.lang.annotation.*;


class Expressions {
  void instanceOf() {
    Object o = null;
    boolean a = o instanceof @A String;
    boolean b = o instanceof @B(0) String;
  }

  void instanceOfArray() {
    Object o = null;
    boolean a1 = o instanceof @A String [];
    boolean a2 = o instanceof @B(0) String [];

    boolean b1 = o instanceof String @A [];
    boolean b2 = o instanceof String @B(0) [];
  }

  void objectCreation() {
    new @A String();
    new @B(0) String();
  }

  void objectCreationArray() {
    Object a1 = new @A String [] [] { };
    Object a2 = new @A String [1] [];
    Object a3 = new @A String [1] [2];

    Object b1 = new @A String @B(0) [] [] { };
    Object b2 = new @A String @B(0) [1] [];
    Object b3 = new @A String @B(0) [1] [2];

    Object c1 = new @A String []  @B(0) [] { };
    Object c2 = new @A String [1] @B(0) [];
    Object c3 = new @A String [1] @B(0) [2];

    Object d1 = new @A String @B(0) []  @B(0) [] { };
    Object d2 = new @A String @B(0) [1] @B(0) [];
    Object d3 = new @A String @B(0) [1] @B(0) [2];

    Object rand = new @A String @B(value = 0) [1] @B(value = 0) [2];

  }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { int value(); }
