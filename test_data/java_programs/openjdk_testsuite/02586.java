


import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;
import static java.lang.annotation.ElementType.*;
import java.util.List;

class T8008751 {
    Object mtest( T8008751 t){ return null;  }
    public void test() {
       mtest( new T8008751() {
                class InnerAnon {
                    @A("ok") String s = (@A("ok") String)( new @A("ok") Object());
                    @A("ok") Object @A("NPE")[] [] ia_sa1 = null;
                }
                
                InnerAnon IA = new InnerAnon();
           });
   }
}
@Retention(RUNTIME) @Target(TYPE_USE)  @interface A { String value(); }
