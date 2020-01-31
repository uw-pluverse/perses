


import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;
import static java.lang.annotation.ElementType.*;

class Test1<T> {
    Object mtest( Test1<T> t){ return null; }
    public void test() {
        mtest( new Test1<T>() {
                @A String data1 = "test";    
                @A @A String data2 = "test"; 
                @A @B String data3 = "test"; 
                @B @C String data4 = "test"; 
           });
   }
}

@Target({TYPE_USE,FIELD}) @Repeatable( AC.class) @interface A { }
@Target({TYPE_USE,FIELD}) @interface AC { A[] value(); }
@Target({TYPE_USE}) @interface B { }
@Target({TYPE_USE, FIELD}) @interface C { }
