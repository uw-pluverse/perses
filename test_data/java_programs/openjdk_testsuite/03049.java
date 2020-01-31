



import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

interface X extends A, B, C {
   default String u() { return " "; }
   default String name() {
      return A.super.name() + B.super.name() + C.super.name();
   }
}

public class PrivateLambdas implements X {
   public static void main(String[] args) throws Exception {

      
      for (Class<?> k : new Class<?>[] { A.class, B.class, C.class }) {
         Method[] methods = k.getDeclaredMethods();
         int lambdaCount = 0;
         for(Method m : methods) {
            if (m.getName().startsWith("lambda$")) {
               ++lambdaCount;
               int mod = m.getModifiers();
               if ((mod & Modifier.PRIVATE) == 0) {
                  throw new Exception("Expected " + m + " to be private");
               }
               if (!m.isSynthetic()) {
                  throw new Exception("Expected " + m + " to be synthetic");
               }
               if ((mod & Modifier.STATIC) != 0) {
                  throw new Exception("Expected " + m + " to be instance method");
               }
            }
         }
         if (lambdaCount == 0) {
            throw new Exception("Expected at least one lambda method");
         }
      }

      
      X x = new PrivateLambdas();
      if (!x.name().equals(" A B C")) {
         throw new Exception("Expected ' A B C' got: " + x.name());
      }
   }
}
