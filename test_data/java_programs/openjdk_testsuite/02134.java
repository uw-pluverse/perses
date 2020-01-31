

import java.util.List;

class T6993978neg {
   @SuppressWarnings({"varargs","unchecked"})
   static <X> void m(X... x) {  }
   static void test(List<String> ls) {
       m(ls); 
   }
}
