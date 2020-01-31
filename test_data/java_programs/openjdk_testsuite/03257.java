

class BadReturn {

    interface SAM {
        Comparable<?> m();
    }

    static void testNeg1() {
        SAM s = ()-> {
            if (true) {
                return "";
            } else {
                return System.out.println("");
            }};
    }

    static void testNeg2() {
        SAM s = ()-> { return System.out.println(""); };
    }

    static void testPos() {
        SAM s = ()-> {
            if (false) {
                return 10;
            }
            else {
                return true;
            }};
    }
}
