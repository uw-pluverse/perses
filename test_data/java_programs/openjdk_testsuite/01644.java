





public class Pos12 {

    public static void main(String... args) {
        try {
            new Pos12().test();
        } catch (A exception) {
            try {
                try {
                    throw exception; 
                } catch (Ac cException) { 
                    throw new RuntimeException("FAIL: Should not be caught in catch Ac");
                }
            } catch (Ab | Ac bcException) {
                if (bcException instanceof Ac) {
                    throw new RuntimeException("FAIL: Sibling exception Ab not caught as expected");
                } else if (bcException instanceof Ab) {
                    System.out.println("PASS");
                }
            }
        }
    }

    public void test() { throw new Ab(); }

    static class A extends RuntimeException {}

    
    static class Ab extends A {}

    
    static class Ac extends A {}
}

