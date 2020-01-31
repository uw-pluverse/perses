

import java.lang.annotation.*;
import java.util.Map;


class Outer {
    class Inner {
        class Inner2 {
            
            void m1a(@A Inner2 p1a) {}
            void m1b(Inner.@A Inner2 p1b) {}
            void m1c(Outer.Inner.@A Inner2 p1c) {}
            
            void m1d(@A Outer.Inner.Inner2 p1d) {}

            
            void m2a(@A Inner.Inner2 p2a) {}
            void m2b(Outer.@A Inner.Inner2 p2b) {}

            
            void m3a(@A Outer p3a) {}
            void m3b(@A Outer.Inner p3b) {}
            void m3c(@A Outer.Inner.Inner2 p3c) {}

            
            void m4a(@A Outer p3a) {}
            void m4b(@A Outer. @B Inner p3b) {}
            void m4c(@A Outer. @B Inner. @C Inner2 p3c) {}
        }
    }

    void m4a(@A Map p4a) {}
    void m4b(Map.@B Entry p4c) {}
    
    
    

    void m4c(Map<String,String>.@B Entry<String,String> p4d) {}
    
    

    void m4e(MyList<Map.Entry> p4e) {}
    void m4f(MyList<Map.@B Entry> p4f) {}
    
    
    

    class GInner<X> {
        class GInner2<Y, Z> {}
    }

    static class Static {}
    static class GStatic<X, Y> {
        static class GStatic2<Z> {}
    }
}

class Test1 {
    
    Outer.GStatic.@A GStatic2<Object> gsgood;
    
    

    MyList<@A Outer . @B Inner. @C Inner2> f;
    @A Outer .GInner<Object>.GInner2<String, Integer> g;

    
    

    @A Outer f1;
    @A Outer . @B Inner f2 = f1.new @B Inner();
    
    @A Outer . @B GInner<@C Object> f3 = f1.new @B GInner<@C Object>();

    MyList<@A Outer . @B GInner<@C MyList<@D Object>>. @E GInner2<@F Integer, @G Object>> f4;
    

    @A Outer . @B GInner<@C MyList<@D Object>>. @E GInner2<@F Integer, @G Object> f4top;

    MyList<@A Outer . @B GInner<@C MyList<@D Object @E[] @F[]>>. @G GInner2<@H Integer, @I Object> @J[] @K[]> f4arr;

    @A Outer . @B GInner<@C MyList<@D Object @E[] @F[]>>. @G GInner2<@H Integer, @I Object> @J[] @K[] f4arrtop;

    MyList<Outer . @B Static> f5;
    
    

    Outer . @B Static f6;
    
    

    Outer . @Bv("B") GStatic<@Cv("C") String, @Dv("D") Object> f7;
    
    

    Outer . @Cv("Data") Static f8;
    
    

    MyList<Outer . @Cv("Data") Static> f9;
    
    
}

class Test2 {
    void m() {
        @A Outer f1 = null;
        @A Outer.@B Inner f2 = null;
        Outer.@B Static f3 = null;
        
        
        @A Outer.@C Inner f4 = null;

        Outer . @B Static f5 = null;
        Outer . @Cv("Data") Static f6 = null;
        MyList<Outer . @Cv("Data") Static> f7 = null;
    }
}

class Test3 {
    void monster(@A Outer p1,
        @A Outer.@B Inner p2,
        Outer.@B Static p3,
        @A Outer.@Cv("Test") Inner p4,
        Outer . @B Static p5,
        Outer . @Cv("Data") Static p6,
        MyList<Outer . @Cv("Data") Static> p7) {
    }
}

class Test4 {
    void m() {
        @A Outer p1 = new @A Outer();
        @A Outer.@B Inner p2 = p1.new @B Inner();
        
        
        

        @A Outer.@Cv("Test") Inner p4 = p1.new @Cv("Test") Inner();
        Outer . @B Static p5 = new Outer . @B Static();
        Outer . @Cv("Data") Static p6 = new Outer . @Cv("Data") Static();
        MyList<Outer . @Cv("Data") Static> p7 = new MyList<Outer . @Cv("Data") Static>();
    }
}

class MyList<K> { }


@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface C { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface D { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface E { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface F { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface G { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface H { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface I { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface J { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface K { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Av { String value(); }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Bv { String value(); }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Cv { String value(); }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Dv { String value(); }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Ev { String value(); }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface Fv { String value(); }

