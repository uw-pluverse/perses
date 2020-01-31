

import java.lang.annotation.*;

import java.io.*;



class ExceptionParameters {

  void exception() {
    try {
      foobar();
    } catch (@A Exception e) {
      e.toString();
    }
  }

  void finalException() {
    try {
      foobar();
    } catch (final @B Exception e) {
      e.toString();
    }
  }

  void multiException1() {
    try {
      foobar();
    } catch (@A NullPointerException | @B IndexOutOfBoundsException e) {
      e.toString();
    }
  }

  void multiException2() {
    try {
      foobar();
    } catch (java.lang.@A NullPointerException | java.lang.@B IndexOutOfBoundsException e) {
      e.toString();
    }
  }

  void foobar() {}
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
