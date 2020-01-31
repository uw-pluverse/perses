



public class MethodReference30 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
       void m();
    }

    MethodReference30() {
        assertTrue(true);
    }

   void m() { }

   public static void main(String[] args) {
      SAM s = new MethodReference30()::m;
      assertTrue(assertionCount == 1);
   }
}
