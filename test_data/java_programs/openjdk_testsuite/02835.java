



public class X<T> {
   private T t;
   X(T t) {
       this.t = t;
   }
   public static void main(String[] args) {
       new X<String>("OUTER").bar();
   }
   void bar() {
       new X<X>(this) {     
           void run() {
               new Object() {  
                   void run() {
                       X x = t;        
                   System.out.println(x);
                   }
               }.run();
           }
       }.run();
   }
}
