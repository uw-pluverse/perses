



public class InnerConstructor {

    public static void main(String... args) {
        InnerConstructor ic = new InnerConstructor();
        String res = ic.seq1().m().toString();
        if (!res.equals("Cbl.toString")) {
            throw new AssertionError(String.format("Unexpected result: %s", res));
        }
    }

    Ib1 seq1() {
        return () -> new Cbl();
    }

    class Cbl {
        Cbl() {  }
        public String toString() {
            return "Cbl.toString";
        }
    }

    interface Ib1 {
        Object m();
    }
}
