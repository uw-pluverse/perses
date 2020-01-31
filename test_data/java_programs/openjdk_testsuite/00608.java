



public class SuperNew2 {
    int x;

    class Dummy {
        Dummy(Object o) {}
    }

    class Inside extends Dummy {
        Inside(final int y) {
            super(new Object() { int r = y; }); 
        }
    }

    public static void main(String[] args) {
        Object o = new SuperNew2().new Inside(12);
    }
}
