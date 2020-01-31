

import java.util.List;
import java.util.ArrayList;

import java.lang.annotation.*;

@Target({ElementType.TYPE_USE})
@interface TA {}
@Target({ElementType.TYPE_USE})
@interface TA2 {}

@Target({ElementType.FIELD})
@interface DA {}
@Target({ElementType.FIELD})
@interface DA2 {}

@Target({ElementType.TYPE_USE, ElementType.FIELD})
@interface DTA {}
@Target({ElementType.TYPE_USE, ElementType.FIELD})
@interface DTA2 {}

class Test {
    static class Outer {
        static class SInner {}
    }

    
    List<Outer. @TA SInner> li;

    
    @TA Outer.SInner osi;
    
    List<@TA Outer.SInner> aloi;
    
    Object o1 = new @TA @DA @TA2 Outer.SInner();
    
    Object o = new ArrayList<@TA @DA Outer.SInner>();

    
    @TA java.lang.Object f1;

    
    @DA java.lang.Object f2;

    
    @DTA java.lang.Object f3;

    
    @DTA @DA @TA @DA2 @TA2 java.lang.Object f4;

    
    
    
    java. @DA lang.Object f5;

    
    
    
    java. @DA XXX.Object f6;

    
    
    java. @TA lang.Object f7;
}
