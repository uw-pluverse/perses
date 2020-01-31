


public class LambdaConv27 {

     public static void main(String[] args) {
         SAM s = ()-> { SAM s2 = ()->{ new Object() { }; }; s2.m(); };
         s.m();
     }

     interface SAM {
         void m();
     }
}
