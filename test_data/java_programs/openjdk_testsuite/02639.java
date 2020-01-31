



class E1 extends Exception {}
class E2 extends Exception {}

public class DefAssignAfterTry1 {
    public static void main(String argv[]) {
        boolean t = true;
        E1 se1 = new E1();
        E2 se2 = new E2();
        int i;
        try {
            if (t) {
                throw se1;
            }
        } catch (E1 e) {
            i = 0;
        }
        
        
        System.out.println(i);
        System.out.println("Error : there should be compile-time errors");
    }
}
